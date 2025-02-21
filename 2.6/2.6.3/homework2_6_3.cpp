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

	Triangle triangle(10, 20, 30, 50, 60, 70);
	Right_triangle right_triangle(10, 20, 30, 50, 60);
	Isosceles_triangle isosceles_triangle(10, 20, 50, 60);
	Equilateral_triangle equilateral_triangle(30);

	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Parallelogram parallelogram(20, 30, 30, 40);
	Rectangle rectangle(10, 20);
	Rhombus rhombus(30, 30, 40);
	Square square(20);

	print_info(&triangle);
	print_info(&right_triangle);
	print_info(&isosceles_triangle);
	print_info(&equilateral_triangle);

	print_info(&quadrangle);
	print_info(&parallelogram);
	print_info(&rectangle);
	print_info(&rhombus);
	print_info(&square);

	return EXIT_SUCCESS;
}
