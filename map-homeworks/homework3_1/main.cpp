
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <future>
#include <thread>
#include <functional>
#include "print.h"
#include "selectionSort.h"

int main() {
#ifdef _WIN32
    setlocale(LC_ALL, "rus");
#endif

    std::vector<int> v(10);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);
    std::generate(v.begin(), v.end(), [&]() { return dis(gen); });

    std::cout << "Массив до сортировки:" << std::endl;
    print(v);

    std::promise<std::reference_wrapper<std::vector<int>>> prom;
    std::future<std::reference_wrapper<std::vector<int>>> fut{ prom.get_future() };
    std::thread t(selectionSort, std::ref(v), std::move(prom));

    std::cout << "\nМассив после сортировки:" << std::endl;
    print(fut.get());

    t.detach();

    return EXIT_SUCCESS;
}
