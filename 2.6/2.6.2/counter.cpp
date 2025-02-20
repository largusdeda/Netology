#include "counter.h"

Counter::Counter(int count) {
	this->count = count;
}
Counter::Counter() {
	count = 1;
}

int Counter::getCount() {
	return count;
}
void Counter::increment() {
	count++;
}
void Counter::decrement() {
	count--;
}