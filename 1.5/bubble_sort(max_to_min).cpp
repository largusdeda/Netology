#include <iostream>

int main() {
	int arr[] = { 10, 5738, 2232, -47382, -78, 666, 10, 33, -666, -10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bool swapped = false;

	std::cout << "Массив до сортировки: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	do {
		swapped = false;
		for (int i = size - 1; i > 0; i--) {
			if (arr[i - 1] < arr[i]) {
				int tmp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = tmp;
				swapped = true;
			}
		}
	} while (swapped);

	std::cout << "Массив после сортировки: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}