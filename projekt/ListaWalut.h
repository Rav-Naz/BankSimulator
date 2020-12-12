#pragma once
#include "Waluta.h"
class ListaWalut
{
	class Element {
	public:
		Waluta aktualny;
		Element* poprzedni;
		Element* nastepny;
	};

private:
	Element* poczatek = nullptr;
	Element* koniec = nullptr;

public:
	void Dodaj(Waluta* waluta);
	void Usun(int ID);
	void Czytaj();
};

