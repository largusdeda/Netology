#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "rus");
	std::string name{};
	std::cout << "Введите ваше имя: ";
	std::cin >> name;
	std::cout << "Здравствуйте, " << name << std::endl;

	system("pause");
	return 0;
}