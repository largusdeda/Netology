#include "fill_vector.h"

void fill_vector(std::vector<int>& vec) {
	std::mt19937 gen;
	std::uniform_int_distribution<int> dist(0, 100);
	std::generate(std::execution::par, vec.begin(), vec.end(), [&]() {
		return dist(gen);
		});
}