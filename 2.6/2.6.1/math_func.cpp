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
	return static_cast<double>(x) / y;
}

double my_pow(int base, int exp) {
	double result{1};
	if (base == 1 || exp == 0)
		return result;

	int n = exp < 0 ? (-1 * exp) : exp;
	for (int i{0}; i < n; i++) {
		result *= base;
	}

	return exp < 0 ? (1 / result) : result;
}
