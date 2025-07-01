#pragma once

template <typename T>
class my_uniqueptr {
private:
	T* u_ptr{ nullptr };
public:
	my_uniqueptr<T>(T* ptr) : u_ptr{ ptr } {};

	my_uniqueptr<T>(const my_uniqueptr& other) = delete;

	my_uniqueptr<T>(my_uniqueptr&& other) noexcept {
		u_ptr = other.u_ptr;
		other.u_ptr = nullptr;
	}

	~my_uniqueptr<T>() {
		u_ptr = nullptr;
	}

	my_uniqueptr<T>& operator=(const my_uniqueptr& other) = delete;

	my_uniqueptr<T>& operator=(my_uniqueptr&& other) noexcept {
		if (this != &other) {
			u_ptr = other.u_ptr;
			other.u_ptr = nullptr;
		}
		return *this;
	}

	T& operator*() const {
		return *u_ptr;
	}

	T* release() {
		T* rawptr = u_ptr;
		u_ptr = nullptr;
		return rawptr;
	}
};