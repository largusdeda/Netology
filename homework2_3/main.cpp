#include <iostream>
#include <thread>
#include "Data.h"

int main() {
#ifdef _WIN32
	setlocale(LC_ALL, "rus");
#endif

	{
		std::cout << "swap с использованием std::lock" << std::endl;
		Data d1(1, 2, 3);
		Data d2(4, 5, 6);
		std::cout << "d1: ";
		d1.print();
		std::cout << "d2: ";
		d2.print();

		std::thread t1(Data::lock_swap, std::ref(d1), std::ref(d2));
		std::thread t2(Data::lock_swap, std::ref(d1), std::ref(d2));
		std::thread t3(Data::lock_swap, std::ref(d1), std::ref(d2));

		if (t1.joinable()) 
			t1.join();
		if (t2.joinable())
			t2.join();
		if (t3.joinable()) 
			t3.join();

		std::cout << "swap1(d1, d2)" << std::endl;
		std::cout << "d1: ";
		d1.print();
		std::cout << "d2: ";
		d2.print();
	}

	{
		std::cout << "\nswap с использованием std::scoped_lock" << std::endl;
		Data d1(1, 2, 3);
		Data d2(4, 5, 6);
		std::cout << "d1: ";
		d1.print();
		std::cout << "d2: ";
		d2.print();

		std::thread t1(Data::scoped_lock_swap, std::ref(d1), std::ref(d2));
		std::thread t2(Data::scoped_lock_swap, std::ref(d1), std::ref(d2));
		std::thread t3(Data::scoped_lock_swap, std::ref(d1), std::ref(d2));

		if (t1.joinable())
			t1.join();
		if (t2.joinable())
			t2.join();
		if (t3.joinable())
			t3.join();

		std::cout << "swap2(d1, d2)" << std::endl;
		std::cout << "d1: ";
		d1.print();
		std::cout << "d2: ";
		d2.print();
	}

	{
		std::cout << "\nswap с использованием std::unique_lock" << std::endl;
		Data d1(1, 2, 3);
		Data d2(4, 5, 6);
		std::cout << "d1: ";
		d1.print();
		std::cout << "d2: ";
		d2.print();

		std::thread t1(Data::unique_lock_swap, std::ref(d1), std::ref(d2));
		std::thread t2(Data::unique_lock_swap, std::ref(d1), std::ref(d2));
		std::thread t3(Data::unique_lock_swap, std::ref(d1), std::ref(d2));
		
		if (t1.joinable())
			t1.join();
		if (t2.joinable())
			t2.join();
		if (t3.joinable())
			t3.join();

		std::cout << "swap3(d1, d2)" << std::endl;
		std::cout << "d1: ";
		d1.print();
		std::cout << "d2: ";
		d2.print();
	}

	return EXIT_SUCCESS;
}