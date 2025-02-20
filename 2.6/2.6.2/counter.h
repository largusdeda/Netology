#pragma once

class Counter {
private:
	int count;
public:
	Counter(int count);
	Counter();

	int getCount();
	void increment();
	void decrement();
};