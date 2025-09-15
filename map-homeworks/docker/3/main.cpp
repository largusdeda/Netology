#include <iostream>
#include <vector>
#include <chrono>
#include "async_for_each.h"

int main() {
#ifdef _WIN32
	setlocale(LC_ALL, "rus");
#endif

	std::vector<double> v(1'000'000, 0.5);

	auto start{ std::chrono::steady_clock::now() };
	async_for_each(v.begin(), v.end(), [](double& value) { value *= 2; });
	auto finish{ std::chrono::steady_clock::now() };

	std::chrono::duration<double, std::milli> delta{ std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start) };
	std::cout << "Время работы функции: " << delta.count() << " ms";

	return EXIT_SUCCESS;
}