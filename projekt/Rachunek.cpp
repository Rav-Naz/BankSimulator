#include "Rachunek.h"

Rachunek::Rachunek(int Numer, int UzytkownikID) {
	this->_numer = Numer;
	this->_uzytkownikID = UzytkownikID;
	this->_nazwa = "Rachunek Oszczêdnoœciowo-Rozliczeniowy";
	this->_rodzajID = 1;
	this->_limitDzienny = 50.0f;
	this->_limitMiesieczny = 1000.0f;
	this->_saldo = 0.0;
	this->_walutaID = 1;
};
Rachunek::Rachunek(int Numer, int UzytkownikID, char* Nazwa, int RodzajID, float LimitDzienny, float LimitMiesieczny, double Saldo, int WalutaID) {
	this->_numer = Numer;
	this->_uzytkownikID = UzytkownikID;
	this->_nazwa = Nazwa;
	this->_rodzajID = RodzajID;
	this->_limitDzienny = LimitDzienny;
	this->_limitMiesieczny = LimitMiesieczny;
	this->_saldo = Saldo;
	this->_walutaID = WalutaID;
};
Rachunek::Rachunek(Rachunek& Wzor) {
	this->_numer = Wzor.Numer();
	this->_uzytkownikID = Wzor.UzytkownikID();
	this->_nazwa = Wzor.Nazwa();
	this->_rodzajID = Wzor.RodzajID();
	this->_limitDzienny = Wzor.LimitDzienny();
	this->_limitMiesieczny = Wzor.LimitMiesieczny();
	this->_saldo = Wzor.Saldo();
	this->_walutaID = Wzor.WalutaID();
};
Rachunek::~Rachunek() {
	delete this;
};

int Rachunek::Numer() {
	return this->_numer;
};
int Rachunek::UzytkownikID() {
	return this->_uzytkownikID;
};
char* Rachunek::Nazwa() {
	return this->_nazwa;
};
int Rachunek::RodzajID() {
	return this->_rodzajID;
};
float Rachunek::LimitDzienny() {
	return this->_limitDzienny;
};
float Rachunek::LimitMiesieczny() {
	return this->_limitMiesieczny;
};
double Rachunek::Saldo() {
	return this->_saldo;
};
int Rachunek::WalutaID() {
	return this->_walutaID;
};