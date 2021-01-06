#pragma once
#include <string>
class Operacja
{
private:
	std::string _numerNadawcy;
	std::string _numerOdbiorcy;
	std::string _data;
	float _kwota;
	std::wstring _tytul;

public:
	Operacja(std::string NumerNadawcy, std::string NumerOdbiorcy, float Kwota, std::wstring tytul);
	Operacja(std::string NumerNadawcy, std::string NumerOdbiorcy, float Kwota, std::string Data, std::wstring tytul);

	std::string NumerNadawcy();
	std::string NumerOdbiorcy();
	std::string Data();
	std::wstring Tytul();
	float Kwota();
	
	int ZlecPrzelew();
};

