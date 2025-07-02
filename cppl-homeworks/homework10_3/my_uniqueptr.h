#pragma once
#include <stdexcept>

template <typename T>
class my_uniqueptr {
private:
	T* u_ptr{ nullptr };
public:
	my_uniqueptr<T>(T* ptr) : u_ptr{ ptr } {};

	my_uniqueptr<T>(const my_uniqueptr& other) = delete;

	my_uniqueptr<T>& operator=(const my_uniqueptr& other) = delete;

	my_uniqueptr<T>(my_uniqueptr&& other) noexcept {
		u_ptr = other.u_ptr;
		other.u_ptr = nullptr;
	}

	my_uniqueptr<T>& operator=(my_uniqueptr&& other) noexcept {
		if (this != &other) {
			u_ptr = other.u_ptr;
			other.u_ptr = nullptr;
		}
		return *this;
	}

	~my_uniqueptr<T>() {
		delete u_ptr;
		u_ptr = nullptr;
	}


	T& operator*() const {
		if (!u_ptr) throw std::runtime_error("Null pointer dereference");
		return *u_ptr;
	}

	T* release() {
		T* rawptr = u_ptr;
		u_ptr = nullptr;
		return rawptr;
	}
};