#pragma once
#include "figure.h"

class Triangle : public Figure {
protected:
	int a, b, c, A, B, C;
public:
	Triangle(int a, int b, int c, int A, int B, int C);

	std::string get_name() override;

	std::string get_sides() override;

	std::string get_angles() override;
};