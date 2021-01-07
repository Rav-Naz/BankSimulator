#pragma once
#include <string>
class Rachunek
{
private:
	std::string _numer;
	std::string _uzytkownikID;
	std::wstring _nazwa;
	int _rodzajID;
	float _limitDzienny;
	float _limitMiesieczny;
	double _saldo;
	int _walutaID;
public:
	Rachunek(std::string Numer, std::string UzytkownikID);
	Rachunek(std::string Numer, std::string UzytkownikID, std::wstring Nazwa, int RodzajID, int WalutaID);
	Rachunek(std::string Numer, std::string UzytkownikID, std::wstring Nazwa, int RodzajID, float LimitDzienny, float LimitMiesieczny, double Saldo, int WalutaID);
	Rachunek(Rachunek& Wzor);

	std::string Numer();
	std::string UzytkownikID();
	std::wstring Nazwa();
	int RodzajID();
	float LimitDzienny();
	float LimitMiesieczny();
	double Saldo();
	int WalutaID();

	void AktualizujLimitDzienny(float limit);
	void AktualizujLimitMiesieczny(float limit);
};

