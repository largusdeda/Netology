#pragma once

#include <vector>
#include <future>
#include <functional>
#include <algorithm>

void selectionSort(std::vector<int>& v, std::promise<std::reference_wrapper<std::vector<int>>>&& promise);