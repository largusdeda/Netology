#include <iostream>
#include <vector>
#include "fill_vector.h"
#include "multi_sum.h"

//struct Result {
//	int threads_count{};
//	std::chrono::duration<double, std::milli> time_ms[4];
//};

int main() {
#ifdef _WIN32
		setlocale(LC_ALL, "rus");
#endif

		std::cout << "Количество аппаратных ядер: " << std::thread::hardware_concurrency() << std::endl;
		std::cout << "\t\t" << 1000 << "\t\t" << 10'000 << "\t\t" << 100'000 << "\t\t" << 1'000'000 << std::endl;

		std::vector<int> v1_1(1000);
		std::vector<int> v1_2(1000);
		std::vector<int> v2_1(10'000);
		std::vector<int> v2_2(10'000);
		std::vector<int> v3_1(100'000);
		std::vector<int> v3_2(100'000);
		std::vector<int> v4_1(1'000'000);
		std::vector<int> v4_2(1'000'000);

		fill_vector(v1_1);
		fill_vector(v1_2);
		fill_vector(v2_1);
		fill_vector(v2_2);
		fill_vector(v3_1);
		fill_vector(v3_2);
		fill_vector(v4_1);
		fill_vector(v4_2);

		for (size_t th_cnt{ 1 }; th_cnt <= 16; th_cnt <<= 1) {
			std::cout << th_cnt << " потоков\t";
			multi_sum(th_cnt, v1_1, v1_2);
			multi_sum(th_cnt, v2_1, v2_2);
			multi_sum(th_cnt, v3_1, v3_2);
			multi_sum(th_cnt, v4_1, v4_2);
		}

		return EXIT_SUCCESS;
}