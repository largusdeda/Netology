#include <iostream>

struct address {
  std::string municipality;
  std::string street;
  int houseNumber;
  int flatNumber;
  int postcode;
};

void printAddress(address* adr) {
  std::cout << "Город: " << adr->municipality << std::endl;
  std::cout << "Улица: " << adr->street << std::endl;
  std::cout << "Номер дома: " << adr->houseNumber << std::endl;
  std::cout << "Номер квартиры: " << adr->flatNumber << std::endl;
  std::cout << "Индекс: " << adr->postcode << std::endl;
}

int main() {
  address adr1 = {"Москва", "Арбат", 12, 8, 123456};
  address adr2 = {"Ижевск", "Пушкина", 59, 143, 953769};

  printAddress(&adr1);
  std::cout << "\n";
  printAddress(&adr2);

  return EXIT_SUCCESS;
}
