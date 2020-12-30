#pragma once
#include <string>
#include <iostream>
std::string Szyfruj(std::string slowo) {
	for (int i = 0; i < slowo.length(); i++) {
		if ((int)slowo[i] >= 65 || (int)slowo[i] <= 122) {
			slowo[i] += 2;
		}
	}
	return slowo;
}

std::string Rozszyfruj(std::string slowo) {
	for (int i = 0; i < slowo.length(); i++) {
		if ((int)slowo[i] >= 67 || (int)slowo[i] <= 124) {
			slowo[i] -= 2;
		}
	}
	return slowo;
}