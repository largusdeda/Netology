#include <iostream>
#include <vector>
#include <algorithm>
#include "Counter.h"

int main() {
	std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };

	std::cout << "[IN]: ";
	for (auto& i : numbers)
		std::cout << i << " ";
	std::cout << std::endl;

	Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());
	std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;

	return 0;
}