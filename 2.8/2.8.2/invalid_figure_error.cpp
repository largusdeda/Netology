#include "invalid_figure_error.h"

invalid_figure_error::invalid_figure_error(const std::string &message) : std::domain_error(message) 
{}