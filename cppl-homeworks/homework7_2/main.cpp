#include <iostream>
#include <set>

struct Comp {
	bool operator()(int a, int b) const {
		return a > b; 
	}
};

int main() {
	std::cout << "[IN]: " << std::endl;
	int n{};
	std::cin >> n;

	std::set<int, Comp> nums;
	for (int i{ 0 }; i < n; i++) {
		int num{};
		std::cin >> num;
		nums.insert(num);
	}

	std::cout << "[OUT]: " << std::endl;
	for (auto& num : nums) {
		std::cout << num << std::endl;
	}

	return EXIT_SUCCESS;
}