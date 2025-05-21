#include <iostream>
#include "smart_array.h"

int main() {
#ifdef _WIN32
	setlocale(LC_ALL, "rus");
#endif

	try {
		smart_array arr(5);
		//smart_array arr(-4); //ошибка создания массива
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		//arr.add_element(24); // ошибка добавления элемента
		std::cout << arr.get_element(1) << std::endl;
		//std::cout << arr.get_element(8) << std::endl; // ошибка при обращении к элементу массива
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}