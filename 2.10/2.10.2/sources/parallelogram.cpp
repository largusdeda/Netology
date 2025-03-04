#include "headers/parallelogram.h"

Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
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