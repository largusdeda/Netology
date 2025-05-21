#include "array_ex.h"

ArrayException::ArrayException(const std::string& message) : std::runtime_error(message)
{ }