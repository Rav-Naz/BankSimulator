#pragma once
#include <mysql.h>
#include <string>
#include <iostream>
#include <list>

#include "Waluta.h"
#include "RodzajRachunku.h"
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
	// Zmienne globalne 
	std::list<Waluta> listaWalut;
	std::list<RodzajRachunku> listaRodzajiRachunkow;
	// Logowanie
	int Logowanie(std::string id_uzytkownika, std::string haslo);
	// Waluty
	void PobierzWaluty();
	// Rodzaj rachunku
	void PobierzRodzajeRachunku();
private:
	API() {};
	MYSQL * conn;
};

