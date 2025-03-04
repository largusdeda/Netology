#include <iostream>
#include "headers/print_info.h"

void print_info(Figure *f) {
	std::cout << f->get_name() << ": " << std::endl;
	std::cout << "�������: " << f->get_sides() << std::endl;
	std::cout << "����: " << f->get_angles() << std::endl;
	std::cout << std::endl;
}