#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
	std::string str{ "Hello world!!" };

	std::cout << "[IN]: " << str << std::endl;

	std::unordered_map<char, int> char_count;
	for (int i{ 0 }; i < str.length(); i++) {
		char_count[str[i]]++;
	}

	std::vector<std::pair<char, int>> vec(char_count.begin(), char_count.end());
	std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
	std::cout << "[OUT]: " << std::endl;
	for (auto& el : vec) {
		std::cout << el.first << ": " << el.second << std::endl;
	}

	return EXIT_SUCCESS;
}