#include "selectionSort.h"

void selectionSort(std::vector<int>& v, std::promise<std::reference_wrapper<std::vector<int>>>&& promise) {

	auto findMin = [&v](std::vector<int>::iterator it) {
		auto it_min{ it };
		for (auto j{ it + 1 }; j != v.end(); j++) {
			if (*j < *it_min)
				it_min = j;
		}

		return it_min;
	};

	for (auto i{ v.begin() }; i != v.end(); i++) {
		auto fut{ std::async(std::launch::async, findMin, i)};
		std::iter_swap(fut.get(), i);
	}

	promise.set_value(std::ref(v));
}