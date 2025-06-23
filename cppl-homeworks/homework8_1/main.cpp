#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };

	auto print = [](const std::vector<int>& vec) {
		for (const auto& el : vec)
			std::cout << el << " ";
		std::cout << std::endl;
		};

	std::cout << "[IN]: ";
	print(vec);

	std::sort(vec.begin(), vec.end());
	auto it = std::unique(vec.begin(), vec.end());
	vec.erase(it, vec.end());

	std::cout << "[OUT]: ";
	print(vec);

	return EXIT_SUCCESS;
}
