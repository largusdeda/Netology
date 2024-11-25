#include <iostream>

int main() {

	int arr[][6] = { {0, 4, -1, 333, 666, -9}, {9, 18, 14, -2, 6, 32}, {1, 2, 99, 42, 14, -666} };
	int min = arr[0][0], max = min;
	int indexMin1{ 0 }, indexMin2{ 0 };
	int indexMax1{ 0 }, indexMax2{ 0 };

	int rows = sizeof(arr) / sizeof(arr[0]);
	int cols = sizeof(arr[0]) / sizeof(arr[0][0]); //а вдруг забудем???
	
	std::cout << "Массив:" << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << arr[i][j] << "\t";
			if (arr[i][j] < min) {
				min = arr[i][j];
				indexMin1 = i;
				indexMin2 = j;
			}
			if (arr[i][j] > max) {
				max = arr[i][j];
				indexMax1 = i;
				indexMax2 = j;
			}
		}
		std::cout << "\n";
	}

	std::cout << "Индекс минимального элемента массива: " << indexMin1 << " " << indexMin2 
		  << "\nИндекс максимального элемента массива: " << indexMax1 << " " << indexMax2 << std::endl;

	return EXIT_SUCCESS;
}
