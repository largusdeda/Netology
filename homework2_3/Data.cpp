#include "Data.h"

Data::Data(int x, int y, int z) : x(x), y(y), z(z)
{ }

void Data::print() {
	std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
}

std::mutex& Data::get_mutex() {
	return m;
}

void Data::lock_swap(Data& A, Data& B) {
	std::lock(A.get_mutex(), B.get_mutex());
	std::lock_guard<std::mutex> la(A.get_mutex(), std::adopt_lock);
	std::lock_guard<std::mutex> lb(B.get_mutex(), std::adopt_lock);

	std::swap(A.x, B.x);
	std::swap(A.y, B.y);
	std::swap(A.z, B.z);
}

void Data::scoped_lock_swap(Data& A, Data& B) {
	std::scoped_lock sl(A.get_mutex(), B.get_mutex());

	std::swap(A.x, B.x);
	std::swap(A.y, B.y);
	std::swap(A.z, B.z);
}

void Data::unique_lock_swap(Data& A, Data& B) {
	std::unique_lock la(A.get_mutex(), std::defer_lock);
	std::unique_lock lb(B.get_mutex(), std::defer_lock);
	std::lock(la, lb);

	std::swap(A.x, B.x);
	std::swap(A.y, B.y);
	std::swap(A.z, B.z);
}