#include <iostream>
#include "big_int.h"

int main() {
	auto number1 = big_integer("114575");
	auto number2 = big_integer("78524");

	auto result = number1 + number2;
	std::cout << result << std::endl; // 193099

	auto result2 = number1 * number2;
	std::cout << result2; // 8996887300

	auto number3(number1);
	auto number4(std::move(number3));

	number4 = number1;
	number1 = std::move(number4);


	return EXIT_SUCCESS;
}