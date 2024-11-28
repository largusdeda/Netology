//Числа Фибоначчи без рекурсии

#include <iostream>

unsigned long long fibonacci(int n) {
	unsigned long long a{ 0 };
	unsigned long long b{ 1 };

	while (n != 0) {
		a = a + b;
		b = a - b;
		--n;
	}

	return a;
}

int main() {
	int n{};
	std::cout << "Введите число больше нуля: ";
	std::cin >> n;
	std::cout << "Числа Фибоначчи: ";
	for (int i{ 0 }; i < n; i++) {
		std::cout << fibonacci(i) << " ";
	}

	return EXIT_SUCCESS;
}
