#include <iostream>

int main() {
  int arr[] = { -4, 1, 1, 666, -2, 556, -1453, 4, -3738, 2 };
  int min = arr[0], max = min;

  std::cout << "Массив: ";
  for (auto num : arr) {
    std::cout << num << " ";
    if (num < min) {
      min = num;
    }
    if (num > max) {
      max = num;
    }
  }
  std::cout << "\nМинимальный элемент массива: " << min  << "\nМаксимальный элемент массива: " << max << std::endl;

  return EXIT_SUCCESS;
}
