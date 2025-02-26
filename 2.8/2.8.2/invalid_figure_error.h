#pragma once
#include <stdexcept>

class invalid_figure_error : public std::domain_error {
public:
	invalid_figure_error(const std::string& message);
};