#include <mysql.h>
#include <string>
#include <iostream>
#include <list>
#include <locale.h>
#include <stdlib.h>
#include <algorithm>
#include <msclr\marshal_cppstd.h>
#include <cstdlib> 
#include <ctime> 

#include "Waluta.h"
#include "RodzajRachunku.h"
#include "API.h"
#include "Konto.h"
#include "Rachunek.h"

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
	this->uzytkownik = new Konto(id_uzytkownika, haslo);
	MYSQL_ROW row;
	MYSQL_RES* res;
	int loginFailureLimit = 5;
	std::string query;
	query.append("SELECT IF((SELECT COUNT(*) FROM projektcpp.logowania WHERE (DATE(projektcpp.logowania.Data) BETWEEN DATE_ADD(NOW(),INTERVAL -1 DAY) AND NOW()) AND (projektcpp.logowania.Powodzenie = 0) GROUP BY projektcpp.logowania.UzytkownikID) >= ");
	query.append(std::to_string(loginFailureLimit));
	query.append(", -2, (SELECT IF(projektcpp.konta.Haslo = \"");
	query.append(this->uzytkownik->Haslo());
	query.append("\", 1, 0) AS SUKCES FROM projektcpp.konta WHERE projektcpp.konta.UzytkownikID = ");
	query.append(this->uzytkownik->KlientID());
	query.append(")) AS RESPONSE");
	
	const char* q = query.c_str();
	int qstate = mysql_query(this->conn, q);
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		row = mysql_fetch_row(res);
	
		MYSQL_RES* res2;
		std::string query2;
		if (row == NULL) { //Niepoprawny login
			return -1;
		}
		if ((std::string)row[0] == "1") { //Poprawne dane logowania
			query2.append("INSERT INTO projektcpp.logowania (projektcpp.logowania.UzytkownikID, projektcpp.logowania.Powodzenie) VALUES (");
			query2.append(this->uzytkownik->KlientID());
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
			query2.append(this->uzytkownik->KlientID());
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
	this->listaWalut.clear();
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

void API::UtworzNowyRachunek(std::string Nazwa, int RodzajID, int WalutaID) {
	if (!this->isConnected()) { return; }
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query;
	unsigned long nowyNumer = ((1.0f / (float)rand()) * 9999999999) + 1000000000;
	query.append("SELECT ");
	query.append(std::to_string(nowyNumer));
	query.append(" IN (SELECT Numer FROM projektcpp.rachunki);");
	const char* q = query.c_str();
	int qstate;
	qstate = mysql_query(this->conn, q);
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		row = mysql_fetch_row(res);

		if (row == NULL) { //Niepoprawny login
			return;
		}
		if ((std::string)row[0] == "1") {
			this->UtworzNowyRachunek(Nazwa, RodzajID, WalutaID);
			return;
		}
		else {
			Rachunek nowyRachunek = Rachunek(std::to_string(nowyNumer), uzytkownik->KlientID(), Nazwa, RodzajID, WalutaID);
			MYSQL_ROW row2;
			MYSQL_RES* res2;
			std::string query2;
			query2.append("INSERT INTO projektcpp.rachunki (Numer, UzytkownikID, Nazwa, RodzajID, LimitDzienny, LimitMiesieczny, Saldo, WalutaID) VALUES (");
			query2.append(nowyRachunek.Numer() + "," + nowyRachunek.UzytkownikID() + ",\"" + nowyRachunek.Nazwa() + "\"," + std::to_string(nowyRachunek.RodzajID()) + "," + std::to_string(nowyRachunek.LimitDzienny()) + "," + std::to_string(nowyRachunek.LimitMiesieczny()) + "," + std::to_string(nowyRachunek.Saldo()) + "," + std::to_string(nowyRachunek.WalutaID()) + ");");
			const char* q2 = query2.c_str();
			int qstate2;
			qstate2 = mysql_query(this->conn, q2);
			if (!qstate2)
			{
				res2 = mysql_store_result(this->conn);
				return;
			}
			else
			{
				std::cout << "Query failed: " << mysql_error(conn) << std::endl;
				return;
			}
		}

	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
		return;
	}
};

void API::PobierzListeRachunkow() {
	if (!this->isConnected()) { return; }
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query;
	query.append("SELECT * FROM projektcpp.rachunki WHERE UzytkownikID = ");
	query.append(uzytkownik->KlientID() + ";");
	const char* q = query.c_str();
	int qstate;
	qstate = mysql_query(this->conn, q);
	this->listaRachunkow.clear();
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		while (row = mysql_fetch_row(res)) {
			this->listaRachunkow.push_front(Rachunek(row[1], row[2], row[3], atoi(row[4]), atof(row[5]), atof(row[6]), std::stod(row[7]), atoi(row[8])));
		}
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
	}
};

void API::ZmienLimit(std::string Numer, float limit, bool CzyMiesieczny ) {
	if (!this->isConnected()) { return; }
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query;
	query.append("UPDATE projektcpp.rachunki SET ");
	query.append(CzyMiesieczny ? "LimitMiesieczny = " : "LimitDzienny = ");
	query.append(std::to_string(limit));
	query.append(" WHERE Numer = ");
	query.append(Numer + ";");
	std::cout << query;
	const char* q = query.c_str();
	int qstate;
	qstate = mysql_query(this->conn, q);
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		return;
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(this->conn) << std::endl;
		return;
	}
};

// -------------------- Rodzaje rachunków --------------------

void API::PobierzRodzajeRachunku() {
	if (!this->isConnected()) { return ; }
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query = "SELECT * FROM projektcpp.rodzaje_rachunkow ORDER BY ID DESC;";
	const char* q = query.c_str();
	int qstate;
	qstate = mysql_query(this->conn, q);
	this->listaRodzajiRachunkow.clear();
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

// -------------------- Operacje --------------------

int API::ZlecPrzelew(std::string numerNadawcy, std::string numerOdbiorcy, std::string kwota, std::string tytul) {
	if (!this->isConnected()) { return 0; }
	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string query;
	std::string query1;
	std::string query2;
	std::string query3;
	query.append("SELECT " + numerOdbiorcy + " IN (SELECT Numer FROM projektcpp.rachunki) AS Istnieje;");
	const char* q = query.c_str();
	int qstate = mysql_query(this->conn, q);
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		row = mysql_fetch_row(res);
		if ((std::string)row[0] == "0") { // Taki numer rachunku nie istnieje
			return -1;
		}
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
		return 0;
	}
	query1.append("UPDATE projektcpp.rachunki SET Saldo = Saldo - " + kwota + " WHERE Numer = " + numerNadawcy + ";" );
	query2.append("UPDATE projektcpp.rachunki SET Saldo = Saldo + (" + kwota + " * (SELECT(PrzelicznikNadawcy.Przelicznik / PrzelicznikOdbiorcy.Przelicznik) AS Przelicznik FROM(SELECT Przelicznik FROM projektcpp.rachunki LEFT JOIN projektcpp.waluty ON projektcpp.rachunki.WalutaID = projektcpp.waluty.ID WHERE projektcpp.rachunki.Numer = " + numerNadawcy + " LIMIT 1) AS PrzelicznikNadawcy, (SELECT Przelicznik FROM projektcpp.rachunki LEFT JOIN projektcpp.waluty ON projektcpp.rachunki.WalutaID = projektcpp.waluty.ID WHERE projektcpp.rachunki.Numer = " + numerOdbiorcy + " LIMIT 1) AS PrzelicznikOdbiorcy)) WHERE Numer = " + numerOdbiorcy + ";");
	query3.append("INSERT INTO projektcpp.operacje(NumerNadawcy, NumerOdbiorcy, Kwota, Tytul) VALUES(" + numerNadawcy + ", " + numerOdbiorcy + ", " + kwota +", \" " + tytul +"\");");
	const char* q1 = query1.c_str();
	const char* q2 = query2.c_str();
	const char* q3 = query3.c_str();
    mysql_query(this->conn, q1);;
	mysql_query(this->conn, q2);
	mysql_query(this->conn, q3);
	return 1;
};