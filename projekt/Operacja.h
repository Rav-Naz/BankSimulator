#pragma once
#include <string>
class Operacja
{
private:
	int _numerNadawcy;
	int _numerOdbiorcy;
	std::string _data;
	float _kwota;

public:
	Operacja(int NumerNadawcy, int NumerOdbiorcy, float Kwota);
	Operacja(int NumerNadawcy, int NumerOdbiorcy, float Kwota, std::string Data);

	int NumerNadawcy();
	int NumerOdbiorcy();
	std::string Data();
	float Kwota();
};

