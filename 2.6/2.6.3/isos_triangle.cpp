#include "isos_triangle.h"

Isosceles_triangle::Isosceles_triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
	this->a = a;
	this->b = b;
	c = a;
	this->A = A;
	this->B = B;
	C = A;

	name = "Равнобедренный треугольник";
}
