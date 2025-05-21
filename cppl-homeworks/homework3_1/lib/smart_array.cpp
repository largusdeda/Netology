#include "array_ex.h"
#include "smart_array.h"

smart_array::smart_array(const int n) {
	if (n < 1)
		throw ArrayException("Недопустимый размер массива\n");
	ptr = new int[n];
	capacity = n;
	size = 0;
}

void smart_array::add_element(const int el) {
	if (size >= capacity)
		throw ArrayException("Превышен размер умного массива для добавления элементов\n");
	ptr[size++] = el;
}

int smart_array::get_element(const int index) {
	if (index > capacity || index < 0)
		throw ArrayException("Недопустимый индекс при обращении к элементу массива\n");
	return ptr[index];
}

smart_array::~smart_array() {
	delete[] ptr;
	ptr = nullptr;
}