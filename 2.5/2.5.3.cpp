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

    virtual bool check() {
      return true;
    }
    virtual void print_info() {
      std::cout << get_name() << ": " << std::endl;
      std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
      std::cout << "Количество сторон: " << get_sides_count() << std::endl;
      std::cout << std::endl;
    }
};

//Треугольники
class Triangle : public Figure {
  protected:
    int a, b, c, A, B, C;
  public:
    Triangle(int a, int b, int c, int A, int B, int C) {
      this->a = a;
      this->b = b;
      this->c = c;
      this->A = A;
      this->B = B;
      this->C = C;

      sides_count = 3;
      name = "Треугольник";
    }
    
    std::string get_sides() {
      return "a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c);
    }
    std::string get_angles() {
      return "A = " + std::to_string(A) + ", B = " + std::to_string(B) + ", C = " + std::to_string(C);
    }

    bool check() override {
      if (A + B + C == 180) 
        return true;
      else return false;
    }
    void print_info() override {
      std::cout << get_name() << ": " << std::endl;
      std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
      std::cout << "Стороны: " << get_sides() << std::endl;
      std::cout << "Углы: " << get_angles() << std::endl;
      std::cout << std::endl;
    }
};

class Right_triangle : public Triangle {
  public:
    Right_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
      this->a = a;
      this->b = b;
      this->c = c;
      this->A = A;
      this->B = B;
      C = 90;

      name = "Прямоугольный треугольник";
    }

    bool check() override {
      if (Triangle::check() && A + B == 90) 
        return true;
      else return false;
    }
    void print_info() override {
      Triangle::print_info();
    }
};

class Isosceles_triangle : public Triangle {
  public:
    Isosceles_triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
      this->a = a;
      this->b = b;
      c = a;
      this->A = A;
      this->B = B;
      C = A;

      name = "Равнобедренный треугольник";
    }

    bool check() override {
      if (Triangle::check())
        return true;
      else return false;
    }
    void print_info() override {
      Triangle::print_info();
    }
};

class Equilateral_triangle : public Isosceles_triangle {
  public:
    Equilateral_triangle(int a) : Isosceles_triangle(a, a, 60, 60) {
      this->a = a;
      b = a;
      c = a;
      A = 60;
      B = 60;
      C = 60;

      name = "Равносторонний треугольник";
    }
};

//Четырёхугольники
class Quadrangle : public Figure {
  protected:
    int a, b, c, d, A, B, C, D;
  public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
      this->a = a;
      this->b = b;
      this->c = c;
      this->d = d;
      this->A = A;
      this->B = B;
      this->C = C;
      this->D = D;

      sides_count = 4;
      name = "Четырёхугольник";
    }

    std::string get_sides() {
      return "a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c) + ", d = " + std::to_string(d);
    }
    std::string get_angles() {
      return "A = " + std::to_string(A) + ", B = " + std::to_string(B) + ", C = " + std::to_string(C) + ", D = " + std::to_string(D);
    }

    bool check() override {
      if (A + B + C + D == 360) 
        return true;
      else return false;
    }
    void print_info() override {
      std::cout << get_name() << ": " << std::endl;
      std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
      std::cout << "Стороны: " << get_sides() << std::endl;
      std::cout << "Углы: " << get_angles() << std::endl;
      std::cout << std::endl;
    }
};

class Parallelogram : public Quadrangle {
  public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
      this->a = a;
      this->b = b;
      c = a;
      d = b;
      this->A = A;
      this->B = B;
      C = A;
      D = B;

      name = "Параллелограмм";
    }

    bool check() override {
      if (Quadrangle::check() && A + B == 180) 
        return true;
      else return false;
    }
    void print_info() override {
      Quadrangle::print_info();
    }
};

class Rectangle : public Parallelogram {
  public:
    Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {
      this->a = a;
      this->b = b;
      c = a;
      d = b;
      A = 90;
      B = 90;
      C = 90;
      D = 90;

      name = "Прямоугольник";
    }

    bool check() override {
      if (Parallelogram::check())
        return true;
      else return false;
    }
    void print_info() override {
      Parallelogram::print_info();
    }
};

class Rhombus : public Parallelogram {
  public:
    Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) {
      this->a = a;
      b = a;
      c = a;
      d = a;
      this->A = A;
      this->B = B;
      C = A;
      D = B;

      name = "Ромб";
    } 

    bool check() override {
      if (Parallelogram::check())
        return true;
      else return false;
    }
};

class Square : public Rectangle {
  public:
    Square(int a) : Rectangle(a, a) {
      this->a = a;
      b = a;
      c = a;
      d = a;
      A = 90;
      B = 90;
      C = 90;
      D = 90;

      name = "Квадрат";
    }
};

int main() { 
  Figure figure;
  
  Triangle triangle(10, 20, 30, 50, 60, 70);
  Right_triangle right_triangle_1(10, 20, 30, 50, 60);
  Right_triangle right_triangle_2(10, 20, 30, 50, 40);
  Isosceles_triangle isosceles_triangle(10, 20, 50, 60);
  Equilateral_triangle equilateral_triangle(30);
  
  Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
  Parallelogram parallelogram(20, 30, 30, 40);
  Rectangle rectangle(10, 20);
  Rhombus rhombus(30, 30, 40);
  Square square(20);

  figure.print_info();
  
  triangle.print_info();
  right_triangle_1.print_info();
  right_triangle_2.print_info();
  isosceles_triangle.print_info();
  equilateral_triangle.print_info();

  quadrangle.print_info();
  parallelogram.print_info();
  rectangle.print_info();
  rhombus.print_info();
  square.print_info();
  
  return EXIT_SUCCESS;
}
