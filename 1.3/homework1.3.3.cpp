#include <iostream>
#include <algorithm>

int main() { 
  std::string earthSigns[] = {"телец", "дева", "козерог"};
  std::string waterSigns[] = {"рак", "скорпион", "рыбы"};
  std::string sex{};
  std::string sign{};
  int age{};
  
  std::cout << "Введите пол: ";
  std::cin >> sex;
  std::cout << "Введите знак зодиака: ";
  std::cin >> sign;
  std::cout << "Введите возраст: ";
  std::cin >> age;
  std::cout << "Ваше предсказание:" << std::endl;
  
  if (std::find(std::begin(earthSigns), std::end(earthSigns), sign) != std::end(earthSigns)) {
    if (sex == "ж" && age >= 15 && age <= 30) {
      std::cout << "Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок. Будет не только весело, но и интересно: найдётся дело, которое увлечёт всех." << std::endl;
    }
  }
  else if (std::find(std::begin(waterSigns), std::end(waterSigns), sign) != std::end(waterSigns)) {
    if (sex == "м" && age < 40) {
      std::cout << "Сегодня очень плодотворный день. Можно добиться того, что прежде казалось почти невозможным." << std::endl;
    }
  }
  else {
    std::cout << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)" << std::endl;
  }
  
  return EXIT_SUCCESS;
}