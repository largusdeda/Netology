#include "TableHeader.h"

void tableHeader() {
	std::stringstream ss;
	ss << std::setw(2) << " #\t" << "Thread id\t" << "Progress Bar\t\t" << "Time\n";
	std::cout << ss.str();
}