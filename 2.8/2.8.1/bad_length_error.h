#pragma once
#include <exception>

class bad_length_error : public std::exception {
public:
	const char* what() const noexcept override;
};