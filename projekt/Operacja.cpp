#include "Operacja.h"

Operacja::Operacja(int NumerNadawcy, int NumerOdbiorcy, float Kwota) {
	this->_numerNadawcy = NumerNadawcy;
	this->_numerOdbiorcy = NumerOdbiorcy;
	this->_data = "null";
	this->_kwota = Kwota;
};

Operacja::Operacja(int NumerNadawcy, int NumerOdbiorcy, float Kwota, std::string Data) {
	this->_numerNadawcy = NumerNadawcy;
	this->_numerOdbiorcy = NumerOdbiorcy;
	this->_data = Data;
	this->_kwota = Kwota;
};

int Operacja::NumerNadawcy() {
	return this->_numerNadawcy;
};
int Operacja::NumerOdbiorcy() {
	return this->_numerOdbiorcy;
};
std::string Operacja::Data() {
	return this->_data;
};
float Operacja::Kwota() {
	return this->_kwota;
};