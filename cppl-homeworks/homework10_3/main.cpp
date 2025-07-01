#include <iostream>
#include <utility>
#include "my_uniqueptr.h"

int main() {
	int a{ 11 };
	int* ptr_a{ &a };
	my_uniqueptr<int> uptr_a(ptr_a);

	std::cout << *uptr_a << std::endl;

	int b{ 10 };
	int* ptr_b{ &b };
	my_uniqueptr<int> uptr_b(ptr_b);

	//uptr_b = uptr_a;
	uptr_b = std::move(uptr_a);
	//std::cout << *uptr_a << std::endl;
	std::cout << *uptr_b << std::endl;

	my_uniqueptr<int> uptr_c(std::move(uptr_b));
	std::cout << *uptr_c << std::endl;
	*uptr_c = 22;

	ptr_a = uptr_c.release();
	std::cout << *ptr_a << std::endl;

	return EXIT_SUCCESS;
}