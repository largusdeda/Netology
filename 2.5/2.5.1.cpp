#include <iostream>

class Figure {
  protected:
    int sides_count = 0;
    std::string name = "Фигура";
  public:
    int get_sides_count() {
      return sides_count;
    }
    std::string get_name() {
      return name;
    }
};

class Triangle : public Figure {
  public:
    Triangle() {
      sides_count = 3;
      name = "Треугольник";
    }
};

class Quadrangle : public Figure {
  public:
    Quadrangle() {
      sides_count = 4;
      name = "Четырёхугольник";
    }
};

int main() { 
  std::cout << "Количество сторон: " << std::endl;
  Figure figure;
  std::cout << figure.get_name() << ": " << figure.get_sides_count() << std::endl;
  Triangle triangle;
  std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
  Quadrangle quadrangle;
  std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;

  return EXIT_SUCCESS;
}
