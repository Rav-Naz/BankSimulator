#pragma once
#include <ctime>
class Logowanie
{
private:
	int _numerKonta;
	time_t _data; // kiedy zosta³a podjêta próba logowania
	bool _powodzenie; // czy próba logowania siê powiod³a
public:
	Logowanie(int numerKonta, char* haslo);
	~Logowanie();

	int NumerKonta();
	time_t Data();
	bool Powodzenie();
};
