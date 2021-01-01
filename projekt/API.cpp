#include <mysql.h>
#include <string>
#include <iostream>
#include <list>
#include <locale.h>
#include <stdlib.h>
#include <algorithm>
#include <msclr\marshal_cppstd.h>

#include "Waluta.h"
#include "RodzajRachunku.h"
#include "API.h"
#include "Szyfracja.h"

// -------------------- Baza danych --------------------

void API::InitDB(std::string host, std::string user, std::string password, std::string db, int port) {
	this->conn = mysql_init(0);
	this->conn = mysql_real_connect(this->conn, "localhost", "root", "password", "projektcpp", 3307, 0, 0);
};

bool API::isConnected() {
	if (this->conn) {
		return true;
	}
	else {
		return false;
	}
}

// -------------------- Zmienne globalne --------------------



// -------------------- Logowanie --------------------

int API::Logowanie(std::string id_uzytkownika, std::string haslo) {
	if (!this->isConnected()) { return -1; }
	MYSQL_ROW row;
	MYSQL_RES* res;
	int loginFailureLimit = 5;
	std::string query;
	query.append("SELECT IF((SELECT COUNT(*) FROM projektcpp.logowania WHERE (DATE(projektcpp.logowania.Data) BETWEEN DATE_ADD(NOW(),INTERVAL -1 DAY) AND NOW()) AND (projektcpp.logowania.Powodzenie = 0) GROUP BY projektcpp.logowania.UzytkownikID) >= ");
	query.append(std::to_string(loginFailureLimit));
	query.append(", -2, (SELECT IF(projektcpp.konta.Haslo = \"");
	query.append(Szyfruj(haslo));
	query.append("\", 1, 0) AS SUKCES FROM projektcpp.konta WHERE projektcpp.konta.UzytkownikID = ");
	query.append(id_uzytkownika);
	query.append(")) AS RESPONSE");
	
	const char* q = query.c_str();
	int qstate = mysql_query(this->conn, q);
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		row = mysql_fetch_row(res);
	
		MYSQL_ROW row2;
		MYSQL_RES* res2;
		std::string query2;
		if (row == NULL) { //Niepoprawny login
			return -1;
		}
		if ((std::string)row[0] == "1") { //Poprawne dane logowania
			query2.append("INSERT INTO projektcpp.logowania (projektcpp.logowania.UzytkownikID, projektcpp.logowania.Powodzenie) VALUES (");
			query2.append(id_uzytkownika);
			query2.append(",TRUE)");
			const char* q2 = query2.c_str();
			int qstate2 = mysql_query(this->conn, q2);
			if (!qstate2)
			{
				res2 = mysql_store_result(this->conn);
			}
			else
			{
				std::cout << "Query failed: " << mysql_error(conn) << std::endl;
				return -1;
			}
			return 1;
		}
		else if ((std::string)row[0] == "-2") {
			return -2;
		}
		else { //Niepoprawne has³o
			query2.append("INSERT INTO projektcpp.logowania (projektcpp.logowania.UzytkownikID, projektcpp.logowania.Powodzenie) VALUES (");
			query2.append(id_uzytkownika);
			query2.append(",FALSE)");
			const char* q = query2.c_str();
			int qstate2 = mysql_query(this->conn, q);
			if (!qstate2)
			{
				res2 = mysql_store_result(this->conn);
			}
			else
			{
				std::cout << "Query failed: " << mysql_error(conn) << std::endl;
				return -1;
			}
			return 0;
		}
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
		return -1;
	}
	
}

// -------------------- Waluty --------------------

void API::PobierzWaluty() {

	if (!this->isConnected()) { return; }
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query = "SELECT * FROM projektcpp.waluty ORDER BY ID DESC;";
	const char* q = query.c_str();
	int qstate;
	qstate = mysql_query(this->conn, q);
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		while (row = mysql_fetch_row(res))
		{
			this->listaWalut.push_front(Waluta(atoi(row[0]), row[1], atof(row[2])));
		}
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
	}
};

// -------------------- Rachunki --------------------

// -------------------- Rodzaje rachunków --------------------

void API::PobierzRodzajeRachunku() {
	if (!this->isConnected()) { return ; }
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query = "SELECT * FROM projektcpp.rodzaje_rachunkow ORDER BY ID DESC;";
	const char* q = query.c_str();
	int qstate;
	qstate = mysql_query(this->conn, q);
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		while (row = mysql_fetch_row(res)) {
			this->listaRodzajiRachunkow.push_front(RodzajRachunku(atoi(row[0]), row[1], atof(row[2]), atof(row[3])));
		}
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
	}
};