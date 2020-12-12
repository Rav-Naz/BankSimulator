#pragma once
#include <ctime>
class Operacja
{
private:
	int _id;
	int _numerNadawcy;
	int _numerOdbiorcy;
	time_t _data;
	float _kwota;
	bool _zrealizowane;

public:
	Operacja(int numerNadawcy, int numerOdbiorcy, float Kwota, int ID);
	~Operacja();

	int ID();
	int NumerNadawcy();
	int NumerOdbiorcy();
	time_t Data();
	float Kwota();
	bool Zrealizowane();
};

