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

	Table<int> t1(2, 3);
	Table<int> t2(2, 3);
	t1 = t2;

	Table<double> t3(2, 3);
	Table<double> t4(t3);

	return EXIT_SUCCESS;
}
