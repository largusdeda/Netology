#include <iostream>
#include "math_func.h"

int main() {
	setlocale(LC_ALL, "rus");
	int x{}, y{};
	int c{};

	std::cout << "Введите первое число: ";
	std::cin >> x;
	std::cout << "Введите второе число: ";
	std::cin >> y;
	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> c;
	switch (c) {
		case 1:
			std::cout << x << " + " << y << " = " << sum(x, y);
			break;
		case 2:
			std::cout << x << " - " << y << " = " << sub(x, y);
			break;
		case 3:
			std::cout << x << " * " << y << " = " << mult(x, y);
			break;
		case 4:
			std::cout << x << " / " << y << " = " << my_div(x, y);
			break;
		case 5:
			std::cout << x << " в степени " << y << " = " << my_pow(x, y);
			break;
	}

	return EXIT_SUCCESS;
}
