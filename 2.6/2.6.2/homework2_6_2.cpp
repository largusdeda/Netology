#include <iostream>
#include <string>
#include "counter.h"

int main() {
	setlocale(LC_ALL, "rus");

	Counter *c = nullptr;
	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::string answer{};
	std::cin >> answer;
	if (answer == "да") {
		std::cout << "Введите начальное значение счётчика: ";
		int count;
		std::cin >> count;
		c = new Counter(count);
	}
	else {
		c = new Counter();
	}

	char command{};
	do {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> command;
		switch (command) {
		case '+':
			c->increment();
			break;
		case '-':
			c->decrement();
			break;
		case '=':
			std::cout << "Текущее значение счётчика: " << c->getCount() << std::endl;
			break;
		}
	} while (command != 'x');

	std::cout << "До свидания!";

	delete c;

	return EXIT_SUCCESS;
}

