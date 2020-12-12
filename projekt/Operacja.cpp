#include "Operacja.h"
#include <ctime>

Operacja::Operacja(int numerNadawcy, int numerOdbiorcy, float Kwota, int ID = 0) {
	this->_id = ID;
	this->_numerNadawcy = numerNadawcy;
	this->_numerOdbiorcy = numerOdbiorcy;
	this->_data = time(0);
	this->_kwota = Kwota;
	this->_zrealizowane = false;
};
Operacja::~Operacja() {
	delete this;
};

int Operacja::NumerNadawcy() {
	return this->_numerNadawcy;
};
int Operacja::NumerOdbiorcy() {
	return this->_numerOdbiorcy;
};
time_t Operacja::Data() {
	return this->_data;
};
float Operacja::Kwota() {
	return this->_kwota;
};
bool Operacja::Zrealizowane() {
	return this->_zrealizowane;
};