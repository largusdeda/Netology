#include <iostream>
#include "headers/print_info.h"

namespace Figures {
	void print_info(Figure *f) {
		std::cout << f->get_name() << ": " << std::endl;
		std::cout << "Стороны: " << f->get_sides() << std::endl;
		std::cout << "Углы: " << f->get_angles() << std::endl;
		std::cout << std::endl;
	}
}