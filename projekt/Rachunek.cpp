#include "Rachunek.h"
#include "API.h"
#include <string>
#include <locale>
#include <codecvt>

Rachunek::Rachunek(std::string Numer, std::string UzytkownikID) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	this->_numer = Numer;
	this->_uzytkownikID = UzytkownikID;
	this->_nazwa = converter.from_bytes("Rachunek Oszczêdnoœciowo-Rozliczeniowy");
	this->_rodzajID = 1;
	this->_limitDzienny = 50.0f;
	this->_limitMiesieczny = 1000.0f;
	this->_saldo = 0.0;
	this->_walutaID = 1;
};
Rachunek::Rachunek(std::string Numer, std::string UzytkownikID, std::wstring Nazwa, int RodzajID, int WalutaID) {
	this->_numer = Numer;
	this->_uzytkownikID = UzytkownikID;
	this->_nazwa = Nazwa;
	this->_rodzajID = RodzajID;
	this->_limitDzienny = 50.0f;
	this->_limitMiesieczny = 1000.0f;
	this->_saldo = 0.0;
	this->_walutaID = WalutaID;
};
Rachunek::Rachunek(std::string Numer, std::string UzytkownikID, std::wstring Nazwa, int RodzajID, float LimitDzienny, float LimitMiesieczny, double Saldo, int WalutaID) {
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
std::string Rachunek::Numer() {
	return this->_numer;
};
std::string Rachunek::UzytkownikID() {
	return this->_uzytkownikID;
};
std::wstring Rachunek::Nazwa() {
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

void Rachunek::AktualizujLimitDzienny(float limit) {
	this->_limitDzienny = limit;
	API::Get().ZmienLimit(this->_numer, this->_limitDzienny, false);
}
void Rachunek::AktualizujLimitMiesieczny(float limit) {
	this->_limitMiesieczny = limit;
	API::Get().ZmienLimit(this->_numer, this->_limitMiesieczny, true);
}