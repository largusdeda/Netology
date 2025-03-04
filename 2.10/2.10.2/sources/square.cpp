#include "headers/square.h"

Square::Square(int a) : Rectangle(a, a) {
	this->a = a;
	b = a;
	c = a;
	d = a;
	A = 90;
	B = 90;
	C = 90;
	D = 90;

	name = " вадрат";
}