#include "headers/right_triangle.h"

Right_triangle::Right_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	C = 90;

	name = "Прямоугольный треугольник";
}