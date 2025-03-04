#include "headers/rectangle.h"

Rectangle::Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {
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