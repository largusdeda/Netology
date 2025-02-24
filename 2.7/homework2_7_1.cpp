#define MODE 1

#ifndef MODE
#error Необходимо определить константу MODE
#endif // !MODE

#if MODE == 1
int add(int a, int b) {
	return a + b;
}
#endif

#include <iostream>

int main() {
	setlocale(LC_ALL, "rus");
#if MODE == 0
	std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
	int a{}, b{};
	std::cout << "Работаю в боевом режиме" << std::endl;
	std::cout << "Введите число 1: ";
	std::cin >> a;
	std::cout << "Введите число 2: ";
	std::cin >> b;
	std::cout << "Результат сложения: " << add(a, b);
#else 
	std::cout << "Неизвестный режим. Завершение работы" << std:: endl;
#endif
	return EXIT_SUCCESS;
}