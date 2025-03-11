#include <iostream>
#include <Windows.h>
#include "Greeter.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Greeter::Greeter greeter;
	std::string name{};
    	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << greeter.greet(name);


	return EXIT_SUCCESS;
}
