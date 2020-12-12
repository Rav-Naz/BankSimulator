#include "Logowanie.h"
#include <ctime>

using namespace std;
Logowanie::Logowanie(int numerKonta, char* haslo) {
	this->_numerKonta = numerKonta;
	this->_data = time(0);
	this->_powodzenie = NULL;
	System::Diagnostics::Debug::WriteLine(L"ASD AS DAS DAS D");
};
Logowanie::~Logowanie() {
	delete this;
};

int Logowanie::NumerKonta() {
	return this->_numerKonta;
};
time_t Logowanie::Data() {
	return this->_data;
};
bool Logowanie::Powodzenie() {
	return this->_powodzenie;
};