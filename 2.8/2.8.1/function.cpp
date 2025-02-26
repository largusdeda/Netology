#include "function.h"
#include "bad_length_error.h"

int function(std::string str, int forbidden_length) {
	if (str.length() == forbidden_length)
		throw bad_length_error();
	return str.length();
}