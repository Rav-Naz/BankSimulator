#pragma once
#include <ctime>
class Logowanie
{
private:
	int _numerKonta;
	time_t _data; // kiedy zosta�a podj�ta pr�ba logowania
	bool _powodzenie; // czy pr�ba logowania si� powiod�a
public:
	Logowanie(int numerKonta, char* haslo);
	~Logowanie();

	int NumerKonta();
	time_t Data();
	bool Powodzenie();
};
