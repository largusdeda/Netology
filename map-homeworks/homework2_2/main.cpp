#include <iostream>
#include <vector>
#include <thread>
#include "ProgressBar.h"

int main() {
	int countThreads{ 5 };
	std::vector<std::thread> vectorThreads(countThreads);

    for (size_t i{ 0 }; i < countThreads; i++) {
        vectorThreads[i] = std::thread(progressBar, i);
    }
    for (auto& th : vectorThreads) {
        if (th.joinable())
            th.join();
    }

    std::cout << "\n\n\n\n";

	return EXIT_SUCCESS;
}

