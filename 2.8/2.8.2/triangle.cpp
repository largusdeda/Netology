#include "triangle.h"
#include "invalid_figure_error.h"
#include <iostream>

Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
	if (A + B + C != 180)
		throw invalid_figure_error("������ �������� ������. �������: ����� ����� �� ����� 180\n");
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	name = "�����������";
}

std::string Triangle::get_name() {
	return name;
}

std::string Triangle::get_sides() {
	return "�������: a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c);
}

std::string Triangle::get_angles() {
	return "����: A = " + std::to_string(A) + ", B = " + std::to_string(B) + ", C = " + std::to_string(C);
}