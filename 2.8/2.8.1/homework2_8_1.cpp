#include <iostream>
#include <string>
#include <Windows.h>
#include "bad_length_error.h"
#include "function.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int forbidden_length{};
	std::string str{};

	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;

	try {
		while (true) {
			std::cout << "Введите слово: ";
			std::cin >> str;
			int length{function(str, forbidden_length)};
			std::cout << "Длина слова \"" << str << "\" равна " << length << std::endl;
		}
	}
	catch (const bad_length_error& err) {
		std::cout << err.what() << std::endl;
	}
	catch (...) {
		std::cout << "Неизвестная ошибка" << std::endl;
	}

	return EXIT_SUCCESS;
}