#include "bad_length_error.h"

const char* bad_length_error::what() const noexcept {
	return "Вы ввели слово запретной длины! До свидания";
}