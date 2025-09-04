#pragma once

#include <iostream>
#include <algorithm>
#include <mutex>

class Data {

public:
	Data(int x, int y, int z);

	void print();

	std::mutex& get_mutex();

	// std::lock
	static void lock_swap(Data& A, Data& B);
	// std::scoped_lock
	static void scoped_lock_swap(Data& A, Data& B);
	// std::unique_lock
	static void unique_lock_swap(Data& A, Data& B);

private:
	int x, y, z;
	std::mutex m;

};