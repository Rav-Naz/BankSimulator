#pragma once
#include <ctime>
#include <string>
class Logowanie
{
private:
	std::string _numerKonta;
	time_t _data; // kiedy zosta�a podj�ta pr�ba logowania
	int _powodzenie; // czy pr�ba logowania si� powiod�a
public:
	Logowanie(std::string numerKonta, std::string haslo);

	std::string NumerKonta();
	time_t Data();
	int Powodzenie();
};
