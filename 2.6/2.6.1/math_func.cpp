#include "math_func.h"

int sum(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}

int mult(int x, int y) {
	return x * y;
}

double my_div(int x, int y) {
	double result = static_cast<double>(x) / static_cast<double>(y);
	return result;
}

double my_pow(int base, int exp) {
	if (base == 1 || exp == 0)
		return 1;

	int n = exp < 0 ? (-1 * exp) : exp;
    double result{1};
	for (int i{0}; i < n; i++) {
		result *= base;
	}

	return exp < 0 ? (1 / result) : result;
}