#pragma once

#include <stdexcept>

template<typename T>
class My_Vector {

private:
	const int default_capacity{ 10 };
	T *ptr{ nullptr };
	int current_size{ 0 };
	int full_capacity{ 0 };

	void resize_up() {
		int new_capacity = static_cast<int>(full_capacity * 1.5);
		T *tmp = new T[new_capacity];
		full_capacity = new_capacity;
		for (int i{ 0 }; i < current_size; i++) {
			tmp[i] = ptr[i];
		}
		T *new_ptr = tmp;
		tmp = ptr;
		ptr = new_ptr;
		delete[] tmp;
	}

public:
	My_Vector<T>() {
		ptr = new T[default_capacity];
		current_size = 0;
		full_capacity = default_capacity;
	}

	My_Vector<T>(int n) {
		ptr = new T[n];
		current_size = 0;
		full_capacity = n;
	}

	My_Vector(const My_Vector& other) {
		ptr = new T[other.full_capacity];
		full_capacity = other.full_capacity;
		current_size = other.current_size;
		for (int i{ 0 }; i < current_size; i++) {
			ptr[i] = other.ptr[i];
		}
	}

	My_Vector(My_Vector&& other) {
		ptr = other.ptr;
		full_capacity = other.full_capacity;
		current_size = other.current_size;

		other.full_capacity = 0;
		other.current_size = 0;
		other.ptr = nullptr;
	}

	~My_Vector() {
		delete[] ptr;
		ptr = nullptr;
	}

	My_Vector& operator=(const My_Vector& other) {
		if (this != &other) {
			delete[] ptr;
			ptr = new T[other.full_capacity];
			full_capacity = other.full_capacity;
			current_size = other.current_size;
			for (int i{ 0 }; i < current_size; i++) {
				ptr[i] = other.ptr[i];
			}
		}
		return *this;
	}

	My_Vector& operator=(My_Vector&& other) {
		if (this != &other) {
			delete[] ptr;
			ptr = new T[other.full_capacity];
			full_capacity = other.full_capacity;
			current_size = other.current_size;

			other.full_capacity = 0;
			other.current_size = 0;
			other.ptr = nullptr;
		}
		return *this;
	}

	T& at(int index) const {
		if (index > full_capacity || index < 0)
			throw std::out_of_range("Некорректный индекс обращения к элементу вектора\n");
		return ptr[index];
	}

	void push_back(const T val) {
		if (current_size >= full_capacity)
			resize_up();
		ptr[current_size++] = val;
	}

	int size() {
		return current_size;
	}

	int capacity() {
		return full_capacity - current_size;
	}
};