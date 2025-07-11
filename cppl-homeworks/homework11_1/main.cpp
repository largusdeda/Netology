#include <iostream>
#include <vector>
#include <utility>
#include "move_vec.h"

int main() {
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;

	std::cout << "one: ";
	for (const auto& i : one)
		std::cout << i << " ";
	std::cout << std::endl;

	move_vectors(one, two);

	std::cout << "two: ";
	for (const auto& i : two)
		std::cout << i << " ";
	std::cout << std::endl;

	return EXIT_SUCCESS;
}