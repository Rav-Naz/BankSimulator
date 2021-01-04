#pragma once
#include <mysql.h>
#include <string>
#include <iostream>
#include <list>

#include "Waluta.h"
#include "RodzajRachunku.h"
#include "Konto.h"
#include "Rachunek.h"

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
	Konto* uzytkownik;
	std::list<Waluta> listaWalut;
	std::list<Rachunek> listaRachunkow;
	std::list<RodzajRachunku> listaRodzajiRachunkow;
	// Logowanie
	int Logowanie(std::string id_uzytkownika, std::string haslo);
	// Waluty
	void PobierzWaluty();
	// Rachunki
	void UtworzNowyRachunek(std::string Nazwa, int RodzajID, int WalutaID);
	void PobierzListeRachunkow();
	void ZmienLimit(std::string Numer, float limit, bool CzyMiesieczny);
	// Rodzaj rachunku
	void PobierzRodzajeRachunku();
	// Operacje
	int ZlecPrzelew(std::string numerNadawcy, std::string numerOdbiorcy, std::string kwota, std::string tytul);

private:
	API() {};
	MYSQL * conn;
};

