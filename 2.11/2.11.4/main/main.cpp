#include <iostream>
#include "triangle.h"
#include "right_triangle.h"
#include "isos_triangle.h"
#include "eq_triangle.h"
#include "quadrangle.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "rhombus.h"
#include "square.h"
#include "print_info.h"


int main() {
	setlocale(LC_ALL, "rus");

	Figures::Triangle triangle(10, 20, 30, 50, 60, 70);
	Figures::Right_triangle right_triangle(10, 20, 30, 50, 60);
	Figures::Isosceles_triangle isosceles_triangle(10, 20, 50, 60);
	Figures::Equilateral_triangle equilateral_triangle(30);

	Figures::Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Figures::Parallelogram parallelogram(20, 30, 30, 40);
	Figures::Rectangle rectangle(10, 20);
	Figures::Rhombus rhombus(30, 30, 40);
	Figures::Square square(20);

	Figures::print_info(&triangle);
	Figures::print_info(&right_triangle);
	Figures::print_info(&isosceles_triangle);
	Figures::print_info(&equilateral_triangle);

	Figures::print_info(&quadrangle);
	Figures::print_info(&parallelogram);
	Figures::print_info(&rectangle);
	Figures::print_info(&rhombus);
	Figures::print_info(&square);

	return EXIT_SUCCESS;
}
