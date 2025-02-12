#include <iostream>

class Counter {
  private:
    int count;
  public:
    Counter(int count) {
      this->count = count;
    }
    Counter() {
      count = 1;
    }

    int getCount() {
      return count;
    }
    void increment() {
      count++;
    }
    void decrement() {
      count--;
    }
};

int main() {
  Counter counter;
  std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
  std::string answer;
  std::cin >> answer;
  if (answer == "да") {
    std::cout << "Введите начальное значение счётчика: ";
    int count;
    std::cin >> count;
    counter = Counter(count);
  }

  char command{};
  do {
    std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
    std::cin >> command;
    switch (command) {
      case '+':
        counter.increment();
        break;
      case '-':
        counter.decrement();
        break;
      case '=':
        std::cout << "Текущее значение счётчика: " << counter.getCount() << std::endl;
        break;
    }
  } while(command != 'x');

  std::cout << "До свидания!";
  
  return EXIT_SUCCESS;
}
