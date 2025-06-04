#include <iostream>
#include <vector>

template <typename T>
T square(T a) {
	return a * a;
}

template <typename T>
std::vector<T> square(const std::vector<T>& vect) {
	std::vector<T> sqr_vect = {};
	for (int i{ 0 }; i < vect.size(); i++) {
		sqr_vect.push_back(vect[i] * vect[i]);
	}

	return sqr_vect;
}

int main() {
	int num{ 4 };
	std::cout << "[IN]: " << num << std::endl;
	std::cout << "[OUT]: " << square(num) << std::endl;

	std::vector<int> vect{ {-1, 4, 8} };
	std::cout << "[IN]: ";
	for (auto i{ vect.begin() }; i != vect.end(); i++) {
		std::cout << *i;
		if (std::next(i) != vect.end()) {
			std::cout << ", ";
		}
	}
	std::vector<int> sqr_vect = square(vect);
	std::cout << "\n[OUT]: ";
	for (auto i{ sqr_vect.begin() }; i != sqr_vect.end(); i++) {
		std::cout << *i;
		if (std::next(i) != sqr_vect.end()) {
			std::cout << ", ";
		}
	}

	return EXIT_SUCCESS;
}