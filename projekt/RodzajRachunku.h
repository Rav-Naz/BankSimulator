#pragma once
class RodzajRachunku
{
private:
	int _id;
	char* _nazwa;
	float _oprocentowanie; // w procentach
	float _kosztyMiesieczne;
public:
	RodzajRachunku();
	~RodzajRachunku();
	RodzajRachunku(int ID, char* Nazwa, float Oprocentowanie, float KosztyMiesieczne);
	RodzajRachunku(RodzajRachunku& wzor);

	int ID();
	char* Nazwa();
	float Oprocentowanie();
	float KosztyMiesieczne();
};

