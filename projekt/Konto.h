#pragma once
class Konto
{
private:
	int _id;
	char* _haslo;
	int _klient;
public:
	Konto(int Klient, char* Haslo, int ID);
	~Konto();

	int ID();
	int Klient();
	char* Haslo();

	char* SzyfrujHaslo(char* Haslo);
};

