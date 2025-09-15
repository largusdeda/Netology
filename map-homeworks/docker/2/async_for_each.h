#pragma once

#include <thread>
#include <future>
#include <iterator>
#include <algorithm>

template<typename It, typename Func>
void async_for_each(It begin, It end, Func func) {
	static unsigned int threads{ std::thread::hardware_concurrency() / 2};
	long long curr_size{ std::distance(begin, end) };
	if (curr_size <= 0)
		return;

	static long long block_size{ curr_size / threads };
	if (curr_size <= block_size || block_size == 0) {
		std::for_each(begin, end, func);
	}
	else {
		It mid{ begin + curr_size / 2 };
		std::future<void> first_half{ std::async(std::launch::async, &async_for_each<It, Func>, begin, mid, func) };
		async_for_each(mid, end, func);
		first_half.get();
	}
}