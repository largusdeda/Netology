#include <iostream>
#include <fstream>

class Address {
  private:
    std::string municipality;
    std::string street;
    int houseNumber;
    int flatNumber;

  public:
    Address(std::string municipality, std::string street, int houseNumber, int flatNumber) {
      this->municipality = municipality;
      this->street = street;
      this->houseNumber = houseNumber;
      this->flatNumber = flatNumber;
    }
    ~Address() { }

    std::string getAddress() {
      return municipality + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(flatNumber);
    }
};

int main() {
  int N{};
  std::string municipality{};
  std::string street{};
  int houseNumber{};
  int flatNumber{};

  std::ifstream fin("in.txt");
  if(!fin.is_open()) {
    std::cout << "Не удалось открыть файл!" << std::endl;
    return EXIT_FAILURE;
  }
  
  fin >> N;
  Address *addresses = static_cast<Address*>(operator new[] (N * sizeof(Address)));

  std::ofstream fout("out.txt");
  fout << N << std::endl;
  
  for (int i{0}; i < N; i++) {
    fin >> municipality >> street >> houseNumber >> flatNumber;
    addresses[i] = Address(municipality, street, houseNumber, flatNumber);
    fout << addresses[i].getAddress() << std::endl;
  }

  fin.close();
  fout.close();

  for (int i{0}; i < N; i++) {
    addresses[i].~Address();
  }
  operator delete[] (addresses);
  
  return EXIT_SUCCESS;
}
