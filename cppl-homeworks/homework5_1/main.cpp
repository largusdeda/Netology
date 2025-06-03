#include <iostream>
#include <vector>

template <typename T>
void square(T &a) {
	a *= a;
}

template <>
void square(std::vector<int>& vect) {
	for (auto& i : vect)
		i *= i;
}

int main() {
	int num{ 4 };
	std::cout << "[IN]: " << num << std::endl;
	square(num);
	std::cout << "[OUT]: " << num << std::endl;

	std::vector<int> vect{ {-1, 4, 8} };
	std::cout << "[IN]: ";
	for (auto i{ vect.begin() }; i != vect.end(); i++) {
		std::cout << *i;
		if (std::next(i) != vect.end()) {
			std::cout << ", ";
		}
	}
	square(vect);
	std::cout << "\n[OUT]: ";
	for (auto i{ vect.begin() }; i != vect.end(); i++) {
		std::cout << *i;
		if (std::next(i) != vect.end()) {
			std::cout << ", ";
		}
	}

	return EXIT_SUCCESS;
}