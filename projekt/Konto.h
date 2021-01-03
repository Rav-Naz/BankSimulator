#pragma once
#include <string>

class Konto
{
private:
	std::string _klientId;
	std::string _haslo;
public:
	Konto(std::string KlientID, std::string Haslo);

	std::string KlientID();
	std::string Haslo();

	std::string SzyfrujHaslo(std::string Haslo);
};

