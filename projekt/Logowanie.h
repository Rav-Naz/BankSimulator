#pragma once
#include <ctime>
#include <string>
class Logowanie
{
private:
	std::string _numerKonta;
	time_t _data; // kiedy zosta³a podjêta próba logowania
	int _powodzenie; // czy próba logowania siê powiod³a
public:
	Logowanie(std::string numerKonta, std::string haslo);

	std::string NumerKonta();
	time_t Data();
	int Powodzenie();
};
