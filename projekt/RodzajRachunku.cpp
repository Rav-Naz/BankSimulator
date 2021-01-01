#include "RodzajRachunku.h"

RodzajRachunku::RodzajRachunku() {
	this->_id = 1;
	this->_nazwa = "ROR";
	this->_oprocentowanie = 0.0f;
	this->_kosztyMiesieczne = 1;
};

RodzajRachunku::RodzajRachunku(int ID, std::string Nazwa, float Oprocentowanie, float KosztyMiesieczne) {
	this->_id = ID;
	this->_nazwa = Nazwa;
	this->_oprocentowanie = Oprocentowanie;
	this->_kosztyMiesieczne = KosztyMiesieczne;
};
RodzajRachunku::RodzajRachunku(RodzajRachunku& wzor) {
	this->_id = wzor.ID();
	this->_nazwa = wzor.Nazwa();
	this->_oprocentowanie = wzor.Oprocentowanie();
	this->_kosztyMiesieczne = wzor.KosztyMiesieczne();
};

int RodzajRachunku::ID() {
	return this->_id;
};
std::string RodzajRachunku::Nazwa() {
	return this->_nazwa;
};
float RodzajRachunku::Oprocentowanie() {
	return this->_oprocentowanie;
};
float RodzajRachunku::KosztyMiesieczne() {
	return this->_kosztyMiesieczne;
};