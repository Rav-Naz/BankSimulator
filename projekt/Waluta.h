#pragma once
#include <string>
class Waluta
{
private:
	int _id;
	std::string _nazwa;
	float _przelicznik; // w stosunku do PLN
public:
	Waluta();
	Waluta(int ID, std::string Nazwa, float Przelicznik);
	Waluta(Waluta &wzor);

	int ID();
	std::string Nazwa();
	float Przelicznik();
	float PrzeliczNaWalute(Waluta &wzor);
};

