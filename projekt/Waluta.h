#pragma once
class Waluta
{
private:
	int _id;
	char* _nazwa;
	float _przelicznik; // w stosunku do PLN
public:
	Waluta();
	~Waluta();
	Waluta(int ID, char* Nazwa, float Przelicznik);
	Waluta(Waluta &wzor);

	int ID();
	char* Nazwa();
	float Przelicznik();
	float PrzeliczNaWalute(Waluta &wzor);
};

