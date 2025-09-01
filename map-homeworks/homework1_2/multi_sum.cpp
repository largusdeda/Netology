#include "multi_sum.h"

void multi_sum(size_t threads_count, std::vector<int>& vec1, std::vector<int>& vec2) {
	std::vector<int> res(vec1.size());

	auto sum = [&](int i) {
			for (size_t j = i; j < vec1.size(); j += threads_count) {
				res[j] = std::move(vec1[j] + vec2[j]);
			}
		};

	std::vector<std::thread> v_th;

	auto start = std::chrono::steady_clock::now();

	for (size_t i{ 0 }; i < threads_count; i++) {
		v_th.push_back(std::thread(sum, i));
	}
	for (auto& vt : v_th) {
		if (vt.joinable()) 
			vt.join();
	}

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double, std::milli> time = end - start;
	std::cout << time.count() / 1000 << "s" "\t";
	if (vec1.size() == 1'000'000) 
		std::cout << std::endl;
}