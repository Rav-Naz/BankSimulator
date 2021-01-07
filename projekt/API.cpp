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
#include <locale>
#include <codecvt>
#include <string>

#include "Waluta.h"
#include "RodzajRachunku.h"
#include "API.h"
#include "Konto.h"
#include "Rachunek.h"
#include "Operacja.h"

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

// -------------------- Logowanie --------------------

int API::Logowanie(std::string id_uzytkownika, std::string haslo) {
	if (!this->isConnected()) { return -1; }
	this->uzytkownik = new Konto(id_uzytkownika, haslo);
	MYSQL_ROW row;
	MYSQL_RES* res;
	int loginFailureLimit = 3;
	std::string query;
	query.append("SELECT IF( Count.Count.Count >= 3, -2, (SELECT IF(Haslo = \"" + this->uzytkownik->Haslo() + "\", 1, 0) FROM projektcpp.konta WHERE UzytkownikID = " + this->uzytkownik->KlientID() +")) AS SUKCES FROM (SELECT IFNULL((SELECT COUNT(*) AS Count FROM projektcpp.logowania WHERE (DATE(Data) BETWEEN ADDDATE(NOW(),INTERVAL -1 DAY) AND NOW()) AND (UzytkownikID = " + this->uzytkownik->KlientID() + ") AND (Powodzenie = 0) GROUP BY UzytkownikID),0) AS Count) AS Count");
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

std::string API::UtworzKonto(std::string haslo) {
	if (!this->isConnected()) { return "Error"; }
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query;
	unsigned long noweKonto = ((1.0f / (float)rand()) * 999999) + 100000;
	query.append("SELECT ");
	query.append(std::to_string(noweKonto).substr(0,6));
	query.append(" IN (SELECT UzytkownikID FROM projektcpp.konta);");
	const char* q = query.c_str();
	int qstate;
	qstate = mysql_query(this->conn, q);
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		row = mysql_fetch_row(res);

		if ((std::string)row[0] == "1") {
			this->UtworzKonto(haslo);
		}
		else {
			Konto nowe = Konto(std::to_string(noweKonto).substr(0, 6), haslo);
			MYSQL_ROW row2;
			MYSQL_RES* res2;
			std::string query2;
			query2.append("INSERT INTO projektcpp.konta (UzytkownikID, Haslo) VALUES (");
			query2.append(nowe.KlientID() + ",\"" + nowe.Haslo() + "\");");

			const char* q2 = query2.c_str();
			int qstate2;
			qstate2 = mysql_query(this->conn, q2);
			if (!qstate2)
			{
				res2 = mysql_store_result(this->conn);
				return nowe.KlientID();
			}
			else
			{
				std::cout << "Query failed: " << mysql_error(conn) << std::endl;
				return "Error";
			}
		}

	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
		return "Error";
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

void API::UtworzNowyRachunek(std::wstring Nazwa, int RodzajID, int WalutaID) {
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
			using convert_type = std::codecvt_utf8<wchar_t>;
			std::wstring_convert<convert_type, wchar_t> converter;
			query2.append("INSERT INTO projektcpp.rachunki (Numer, UzytkownikID, Nazwa, RodzajID, LimitDzienny, LimitMiesieczny, Saldo, WalutaID) VALUES (");
			query2.append(nowyRachunek.Numer() + "," + nowyRachunek.UzytkownikID() + ",\"" + converter.to_bytes(nowyRachunek.Nazwa()) + "\"," + std::to_string(nowyRachunek.RodzajID()) + "," + std::to_string(nowyRachunek.LimitDzienny()) + "," + std::to_string(nowyRachunek.LimitMiesieczny()) + "," + std::to_string(nowyRachunek.Saldo()) + "," + std::to_string(nowyRachunek.WalutaID()) + ");");
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
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		while (row = mysql_fetch_row(res)) {
			this->listaRachunkow.push_front(Rachunek(row[1], row[2], converter.from_bytes(row[3]), atoi(row[4]), atof(row[5]), atof(row[6]), std::stod(row[7]), atoi(row[8])));
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
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	this->listaRodzajiRachunkow.clear();
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		while (row = mysql_fetch_row(res)) {
			this->listaRodzajiRachunkow.push_front(RodzajRachunku(atoi(row[0]), converter.from_bytes(row[1]), atof(row[2]), atof(row[3])));
		}
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
	}
};

// -------------------- Operacje --------------------

int API::ZlecPrzelew(Operacja operacja) {
	if (!this->isConnected()) { return 0; }
	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string query;
	std::string query1;
	std::string query2;
	std::string query3;
	std::string query4;
	std::string query5;
	std::string kwota = std::to_string(operacja.Kwota()).substr(0, (std::to_string(operacja.Kwota()).length() - 4));
	query.append("SELECT " + operacja.NumerOdbiorcy() + " IN (SELECT Numer FROM projektcpp.rachunki) AS Istnieje;");
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
	MYSQL_RES* res4;
	MYSQL_ROW row4;
	query4.append("SELECT IF( (IF(Suma.Suma IS NULL, 0, Suma.Suma) + " + kwota + ") > Limity.LimitDzienny,1,0) AS Przekroczony FROM (SELECT SUM(Kwota) AS Suma FROM projektcpp.operacje WHERE NumerNadawcy = " + operacja.NumerNadawcy() + " AND DATE(DataWykonania) = CURDATE()) AS Suma, (SELECT LimitDzienny FROM projektcpp.rachunki WHERE Numer = " + operacja.NumerNadawcy() + ") AS Limity;");
	const char* q4 = query4.c_str();
	int qstate4 = mysql_query(this->conn, q4);
	if (!qstate4)
	{
		res4 = mysql_store_result(this->conn);
		row4 = mysql_fetch_row(res4);
		if ((std::string)row4[0] == "1") { // Przekroczono limit dzienny
			return -2;
		}
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
		return 0;
	}
	MYSQL_RES* res5;
	MYSQL_ROW row5;
	query5.append("SELECT IF((IF(Suma.Suma IS NULL, 0, Suma.Suma) + " + kwota + ") > Limity.LimitMiesieczny,1,0) AS Przekroczony FROM (SELECT SUM(Kwota) AS Suma FROM projektcpp.operacje, (SELECT DATE(CONCAT(SUBSTRING(CURDATE(), 1, 7),\"-01\")) AS Start, ADDDATE(DATE(CONCAT(SUBSTRING(CURDATE(), 1, 7),\"-01\")), INTERVAL 1 MONTH) AS End) AS Daty WHERE NumerNadawcy = " + operacja.NumerNadawcy() + " AND DATE(DataWykonania) >= Daty.Start AND DATE(DataWykonania) < Daty.End) AS Suma, (SELECT LimitMiesieczny FROM projektcpp.rachunki WHERE Numer = " + operacja.NumerNadawcy() + ") AS Limity;");
	const char* q5 = query5.c_str();
	int qstate5 = mysql_query(this->conn, q5);
	if (!qstate5)
	{
		res5 = mysql_store_result(this->conn);
		row5 = mysql_fetch_row(res5);
		if ((std::string)row5[0] == "1") { // Przekroczono limit miesieczny
			return -3;
		}
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
		return 0;
	}
	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;
	std::string narrow = converter.to_bytes(operacja.Tytul());
	query1.append("UPDATE projektcpp.rachunki SET Saldo = Saldo - " + kwota + " WHERE Numer = " + operacja.NumerNadawcy() + ";" );
	query2.append("UPDATE projektcpp.rachunki SET Saldo = Saldo + (" + kwota + " * (SELECT(PrzelicznikNadawcy.Przelicznik / PrzelicznikOdbiorcy.Przelicznik) AS Przelicznik FROM(SELECT Przelicznik FROM projektcpp.rachunki LEFT JOIN projektcpp.waluty ON projektcpp.rachunki.WalutaID = projektcpp.waluty.ID WHERE projektcpp.rachunki.Numer = " + operacja.NumerNadawcy() + " LIMIT 1) AS PrzelicznikNadawcy, (SELECT Przelicznik FROM projektcpp.rachunki LEFT JOIN projektcpp.waluty ON projektcpp.rachunki.WalutaID = projektcpp.waluty.ID WHERE projektcpp.rachunki.Numer = " + operacja.NumerOdbiorcy() + " LIMIT 1) AS PrzelicznikOdbiorcy)) WHERE Numer = " + operacja.NumerOdbiorcy() + ";");
	query3.append("INSERT INTO projektcpp.operacje(NumerNadawcy, NumerOdbiorcy, Kwota, Tytul) VALUES(" + operacja.NumerNadawcy() + ", " + operacja.NumerOdbiorcy() + ", " + kwota +", \" " + narrow +"\");");
	const char* q1 = query1.c_str();
	const char* q2 = query2.c_str();
	const char* q3 = query3.c_str();
    mysql_query(this->conn, q1);;
	mysql_query(this->conn, q2);
	mysql_query(this->conn, q3);
	return 1;
};

void API::PobierzOperacje(Rachunek rachunek) {
	if (!this->isConnected()) { return; }
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query;
	query.append("SELECT NumerNadawcy, NumerOdbiorcy, ROUND(IF(NumerNadawcy = " + rachunek.Numer() + ", Kwota, Kwota * (waluty1.Przelicznik/waluty2.Przelicznik)),2) AS Kwota, Tytul, DATE(DataWykonania) AS Data");
	query.append(" FROM projektcpp.operacje");
	query.append(" LEFT JOIN projektcpp.rachunki AS rachunki1");
	query.append(" ON NumerNadawcy = rachunki1.Numer");
	query.append(" LEFT JOIN projektcpp.rachunki AS rachunki2");
	query.append(" ON NumerOdbiorcy = rachunki2.Numer");
	query.append(" LEFT JOIN projektcpp.waluty AS waluty1");
	query.append(" ON rachunki1.WalutaID = waluty1.ID");
	query.append(" LEFT JOIN projektcpp.waluty AS waluty2");
	query.append(" ON rachunki2.WalutaID = waluty2.ID");
	query.append(" WHERE NumerNadawcy = " + rachunek.Numer() + " OR NumerOdbiorcy = " + rachunek.Numer());
	query.append(" ORDER BY Data ASC; ");
	const char* q = query.c_str();
	int qstate;
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	qstate = mysql_query(this->conn, q);
	this->listaOperacji.clear();
	if (!qstate)
	{
		res = mysql_store_result(this->conn);
		while (row = mysql_fetch_row(res)) {
			std::wstring wide = converter.from_bytes(row[3]);
			this->listaOperacji.push_front(Operacja(row[0], row[1], atof(row[2]), row[4], wide));
		}
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
	}
}