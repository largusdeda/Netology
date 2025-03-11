#include <iostream>
#include <Windows.h>
#include "Leaver.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Leaver::Leaver leaver;
	std::string name{};
    std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << leaver.leave(name);

	return EXIT_SUCCESS;
}
