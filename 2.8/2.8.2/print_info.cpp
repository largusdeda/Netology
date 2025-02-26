#include <iostream>
#include "print_info.h"

void print_info(Figure *f) {
	std::cout << f->get_name() << " (";
	std::cout << f->get_sides() << "; ";
	std::cout << f->get_angles() << ") ";
}