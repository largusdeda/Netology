#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "rus");
	std::string name{};
	std::cout << "������� ���� ���: ";
	std::cin >> name;
	std::cout << "������������, " << name << std::endl;

	system("pause");
	return 0;
}