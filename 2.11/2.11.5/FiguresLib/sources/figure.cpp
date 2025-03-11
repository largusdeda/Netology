#include "headers/figure.h"

namespace Figures {
	std::string Figure::get_name() {
		return name;
	}
	std::string Figure::get_sides() {
		return "Фигура не имеет сторон";
	}
	std::string Figure::get_angles() {
		return "Фигура не имеет углов";
	}
}