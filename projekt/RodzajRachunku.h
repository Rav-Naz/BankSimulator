#pragma once
#include <string>
class RodzajRachunku
{
private:
	int _id;
	std::wstring _nazwa;
	float _oprocentowanie; // w procentach
	float _kosztyMiesieczne;
public:
	RodzajRachunku();
	RodzajRachunku(int ID, std::wstring Nazwa, float Oprocentowanie, float KosztyMiesieczne);
	RodzajRachunku(RodzajRachunku& wzor);

	int ID();
	std::wstring Nazwa();
	float Oprocentowanie();
	float KosztyMiesieczne();
};

