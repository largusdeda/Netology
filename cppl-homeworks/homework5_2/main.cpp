#include <iostream>
#include "table_templ.h"

int main() {
#ifdef _WIN32
	setlocale(LC_ALL, "rus");
#endif

	auto test = Table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0]; // выводит 4

	std::cout << "\nРазмер таблицы: " << test.Size();

	return EXIT_SUCCESS;
}
