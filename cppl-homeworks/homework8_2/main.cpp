#include <iostream>
#include <vector>
#include <set>
#include <list>
#include "print_container.h"

int main() {
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	std::list<std::string> test_list = { "one", "two", "three", "four" };
	std::vector<std::string> test_vector = { "one", "two", "three", "four" };

	print_container(test_set.cbegin(), test_set.cend());
	print_container(test_list.cbegin(), test_list.cend());
	print_container(test_vector.cbegin(), test_vector.cend());

	return EXIT_SUCCESS;
}