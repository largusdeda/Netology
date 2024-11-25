#include <iostream>

int main() {
  int arr1[] = { -4, 1, 0, 666, -2, 5, -1, 4, -864788, 2 };
  int min1 = arr1[0], max1 = min1;

  std::cout << "Массив: ";
  for (auto num : arr1) {
    std::cout << num << " ";
    if (num < min1) {
      min1 = num;
    }
    if (num > max1) {
      max1 = num;
    }
  }
  std::cout << "\nМинимальный элемент массива: " << min1 << std::endl
    << "Максимальный элемент массива: " << max1 << std::endl;

  return EXIT_SUCCESS;
}