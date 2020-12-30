#pragma once
#include <mysql.h>
#include <string>
#include "Waluta.h"
#include <iostream>
class API
{
public:
	static API& Get()
	{
		static API instance;
		return instance;
	}
	API(API const&) = delete;
	void operator=(API const&) = delete;
	// Bazy danych
	void InitDB(std::string host, std::string user, std::string password, std::string db, int port);
	bool isConnected();
	// Logowanie
	int Logowanie(std::string id_uzytkownika, std::string haslo);
	// Waluty
	void PobierzWaluty();
private:
	API() {};
	MYSQL * conn;
};

