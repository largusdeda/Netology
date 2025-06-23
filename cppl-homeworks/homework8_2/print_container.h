#pragma once

template <typename Iter>
void print_container(Iter begin, Iter end) {
	auto it{ begin };
	while (it != end) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}