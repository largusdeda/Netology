#include "headers/rhombus.h"

Rhombus::Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) {
	this->a = a;
	b = a;
	c = a;
	d = a;
	this->A = A;
	this->B = B;
	C = A;
	D = B;

	name = "����";
}