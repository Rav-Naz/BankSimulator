#pragma once
#include <string>
class RodzajRachunku
{
private:
	int _id;
	std::string _nazwa;
	float _oprocentowanie; // w procentach
	float _kosztyMiesieczne;
public:
	RodzajRachunku();
	RodzajRachunku(int ID, std::string Nazwa, float Oprocentowanie, float KosztyMiesieczne);
	RodzajRachunku(RodzajRachunku& wzor);

	int ID();
	std::string Nazwa();
	float Oprocentowanie();
	float KosztyMiesieczne();
};

