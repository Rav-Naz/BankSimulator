#pragma once
class Rachunek
{
private:
	int _numer;
	int _uzytkownikID;
	char* _nazwa;
	int _rodzajID;
	float _limitDzienny;
	float _limitMiesieczny;
	double _saldo;
	int _walutaID;
public:
	Rachunek(int Numer, int Uzytkownik);
	Rachunek(int Numer, int UzytkownikID, char* Nazwa, int RodzajID, float LimitDzienny, float LimitMiesieczny, double Saldo, int WalutaID);
	Rachunek(Rachunek& Wzor);
	~Rachunek();

	int Numer();
	int UzytkownikID();
	char* Nazwa();
	int RodzajID();
	float LimitDzienny();
	float LimitMiesieczny();
	double Saldo();
	int WalutaID();

};

