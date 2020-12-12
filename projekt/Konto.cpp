#include "Konto.h"
#include <iostream>

Konto::Konto(int Klient, char* Haslo, int ID = 0) {
	this->_id = ID;
	this->_klient = Klient;
	this->_haslo = this->SzyfrujHaslo(Haslo);
};
Konto::~Konto() {
	delete this;
};

int Konto::ID() {
	return this->_id;
};
int Konto::Klient() {
	return this->_klient;
};
char* Konto::Haslo() {
	return this->_haslo;
};

char* Konto::SzyfrujHaslo(char* haslo) {

	for (size_t i = 0; (i < strlen(haslo) && haslo[i] != '\0'); i++) {
		haslo[i] = (char)haslo[i] + 2;
	}

	return haslo;

};