#include "Logowanie.h"
#include <ctime>
#include <string>
#include "API.h"

Logowanie::Logowanie(std::string numerKonta, std::string haslo) {
	this->_numerKonta = numerKonta;
	this->_data = time(0);
	this->_powodzenie = API::Get().Logowanie(numerKonta, haslo);
};

std::string Logowanie::NumerKonta() {
	return this->_numerKonta;
};
time_t Logowanie::Data() {
	return this->_data;
};
int Logowanie::Powodzenie() {
	return this->_powodzenie;
};