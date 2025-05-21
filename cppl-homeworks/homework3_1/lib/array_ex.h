#pragma once
#include <stdexcept>
#include <string>

class ArrayException : public std::runtime_error {
public:
	ArrayException(const std::string& err);
};