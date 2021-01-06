#include "Operacja.h"
#include "API.h"

Operacja::Operacja(std::string NumerNadawcy, std::string NumerOdbiorcy, float Kwota, std::wstring tytul) {
	this->_numerNadawcy = NumerNadawcy;
	this->_numerOdbiorcy = NumerOdbiorcy;
	this->_data = "null";
	this->_kwota = Kwota;
	this->_tytul = tytul;
};

Operacja::Operacja(std::string NumerNadawcy, std::string NumerOdbiorcy, float Kwota, std::string Data, std::wstring tytul) {
	this->_numerNadawcy = NumerNadawcy;
	this->_numerOdbiorcy = NumerOdbiorcy;
	this->_data = Data;
	this->_kwota = Kwota;
	this->_tytul = tytul;
};

std::string Operacja::NumerNadawcy() {
	return this->_numerNadawcy;
};
std::string Operacja::NumerOdbiorcy() {
	return this->_numerOdbiorcy;
};
std::string Operacja::Data() {
	return this->_data;
};
std::wstring Operacja::Tytul() {
	return this->_tytul;
};
float Operacja::Kwota() {
	return this->_kwota;
};

int Operacja::ZlecPrzelew() {
	return API::Get().ZlecPrzelew(*this);
}