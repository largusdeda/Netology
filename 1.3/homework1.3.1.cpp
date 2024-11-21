#include <iostream>

int main() { 
  bool boolean1 = true;
  bool boolean2 = false;
  std::cout << std::boolalpha;
  std::cout << "Оператор ||:\n"
            << "true\ttrue\t" << (boolean1 || boolean1) << "\n"
            << "true\tfalse\t" << (boolean1 || boolean2) << "\n"
            << "false\ttrue\t" << (boolean2 || boolean1) << "\n"
            << "false\tfalse\t" << (boolean2 || boolean2) << "\n";
  std::cout << "\nОператор &&:\n"
            << "true\ttrue\t" << (boolean1 && boolean1) << "\n"
            << "true\tfalse\t" << (boolean1 && boolean2) << "\n"
            << "false\ttrue\t" << (boolean2 && boolean1) << "\n"
            << "false\tfalse\t" << (boolean2 && boolean2) << "\n";
            
  return EXIT_SUCCESS;
}