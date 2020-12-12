#include "ListaWalut.h"
#include <iostream>

void ListaWalut::Dodaj(Waluta* waluta) {
	ListaWalut::Element* nowy_element;
	nowy_element = new ListaWalut::Element;
	nowy_element->aktualny = *waluta;
	if (this->poczatek == nullptr) this->poczatek = nowy_element;
	else { this->koniec->nastepny = nowy_element; }
	this->koniec = nowy_element;
	nowy_element->nastepny = nullptr;

};
void ListaWalut::Usun(int ID) {
	ListaWalut::Element* ostatni, *aktualny;
	aktualny = this->poczatek;
	ostatni = aktualny;
	if (ID == 0) {
		this->poczatek = aktualny->nastepny;
		delete aktualny;
	}
	else
	{
		for (int i = 0; i <= ID; i++)
		{
			if (i == (ID - 1)) {
				ostatni = aktualny;
			}
			else if (i == ID) {
				ostatni->nastepny = aktualny->nastepny;
				delete aktualny;
				break;
			}
			if (aktualny->nastepny != nullptr) {
				aktualny = aktualny->nastepny;
			}
			else
			{
				break;
			}
		}
	}
};
void ListaWalut::Czytaj() {
	ListaWalut::Element* temp = this->poczatek;
	std::cout << std::endl;
	while (temp != NULL)
	{
		std::cout << temp->aktualny.Nazwa() << std::endl;
		temp = temp->nastepny;
	}

};