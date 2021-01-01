#include "Waluta.h"
#include <string>

Waluta::Waluta() {
	this->_id = 1;
	this->_nazwa = "PLN";
	this->_przelicznik = 1;
};
Waluta::Waluta(int ID, std::string Nazwa, float Przelicznik) {
	this->_id = ID;
	this->_nazwa = Nazwa;
	this->_przelicznik = Przelicznik;
};
Waluta::Waluta(Waluta& wzor) {
	this->_id = wzor.ID();
	this->_nazwa = wzor.Nazwa();
	this->_przelicznik = wzor.Przelicznik();
};

int Waluta::ID() {
	return this->_id;
};
std::string Waluta::Nazwa() {
	return this->_nazwa;
};
float Waluta::Przelicznik() {
	return this->_przelicznik;
};
float Waluta::PrzeliczNaWalute(Waluta& nowaWaluta) {
	return this->Przelicznik() / nowaWaluta.Przelicznik();
};