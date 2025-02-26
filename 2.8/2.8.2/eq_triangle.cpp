#include "eq_triangle.h"

Equilateral_triangle::Equilateral_triangle(int a) : Isosceles_triangle(a, a, 60, 60) {
	this->a = a;
	b = a;
	c = a;
	A = 60;
	B = 60;
	C = 60;

	name = "Равносторонний треугольник";
}