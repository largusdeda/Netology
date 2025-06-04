#include "Counter.h"

void Counter::operator()(int num) {
	if (0 == num % 3) {
		sum += num;
		count++;
	}
}

int Counter::get_sum() const {
	return sum;
}

int Counter::get_count() const {
	return count;
}