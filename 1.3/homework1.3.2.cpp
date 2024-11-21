#include <iostream>

int main() { 
  int num1{};
  int num2{};
  int num3{};
  
  std::cout << "Введите первое число: ";
  std::cin >> num1;
  std::cout << "Введите второе число: ";
  std::cin >> num2;
  std::cout << "Введите третье число: ";
  std::cin >> num3;
  
  int max = num1 > num2
            ? num1 > num3 ? num1 : num3
            : num2 > num3 ? num2 : num3;
  std::cout << max << std::endl;
  
  return EXIT_SUCCESS;
}