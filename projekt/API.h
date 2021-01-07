#pragma once
#include <mysql.h>
#include <string>
#include <iostream>
#include <list>

#include "Waluta.h"
#include "RodzajRachunku.h"
#include "Konto.h"
#include "Rachunek.h"
#include "Operacja.h"

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
	std::list<Operacja> listaOperacji;
	// Logowanie
	int Logowanie(std::string id_uzytkownika, std::string haslo);
	std::string UtworzKonto(std::string haslo);
	// Waluty
	void PobierzWaluty();
	// Rachunki
	void UtworzNowyRachunek(std::wstring Nazwa, int RodzajID, int WalutaID);
	void PobierzListeRachunkow();
	void ZmienLimit(std::string Numer, float limit, bool CzyMiesieczny);
	// Rodzaj rachunku
	void PobierzRodzajeRachunku();
	// Operacje
	int ZlecPrzelew(Operacja operacja);
	void PobierzOperacje(Rachunek rachunek);

private:
	API() {};
	MYSQL * conn;
};

