﻿#include <iostream>
#include "smart_array.h"

int main() {
#ifdef _WIN32
	setlocale(LC_ALL, "rus");
#endif

    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(arr);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;

	return EXIT_SUCCESS;
}