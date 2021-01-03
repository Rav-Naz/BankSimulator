#include <iostream>
#include <string>

#include "Konto.h"
#include "Szyfracja.h"

Konto::Konto(std::string KlientID, std::string Haslo) {
	this->_klientId = KlientID;
	this->_haslo = this->SzyfrujHaslo(Haslo);
};

std::string Konto::KlientID() {
	return this->_klientId;
};
std::string Konto::Haslo() {
	return this->_haslo;
};

std::string Konto::SzyfrujHaslo(std::string Haslo) {

	return Szyfruj(Haslo);

};