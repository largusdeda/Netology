#include "print.h"

void print(std::vector<int>& v) {
    for (const auto& val : v) {
        std::cout << val << " ";
    }
}