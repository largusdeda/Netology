#include <iostream>

enum class months {
  January = 1,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December
};

int main() {
  while (true) {
    int num{};
    
    std::cout << "Введите номер месяца: ";
    std::cin >> num;

    if (num == 0) {
      std::cout << "До свидания" << std::endl;
      break;
    }

    switch (static_cast<months>(num)) {
      case months::January:
        std::cout << "Январь" << std::endl;
        break;
      case months::February:
        std::cout << "Февраль" << std::endl;
        break;
      case months::March:
        std::cout << "Март" << std::endl;
        break;
      case months::April:
        std::cout << "Апрель" << std::endl;
        break;
      case months::May:
        std::cout << "Май" << std::endl;
        break;
      case months::June:
        std::cout << "Июнь" << std::endl;
        break;
      case months::July:
        std::cout << "Июль" << std::endl;
        break;
      case months::August:
        std::cout << "Август" << std::endl;
        break;
      case months::September:
        std::cout << "Сентябрь" << std::endl;
        break;
      case months::October:
        std::cout << "Октябрь" << std::endl;
        break;
      case months::November:
        std::cout << "Ноябрь" << std::endl;
        break;
      case months::December: 
        std::cout << "Декабрь" << std::endl;
        break;
      default: 
        std::cout << "Неправильный номер!" << std::endl;
    }
  } 

  return EXIT_SUCCESS;
}
