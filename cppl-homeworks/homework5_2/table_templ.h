#pragma once

template<typename T>
class Table {

private:
	T** elements{ nullptr };
	int rows{};
	int cols{};

public:
	Table(int rows, int cols) {
		this->rows = rows;
		this->cols = cols;
		elements = new T*[rows];
		for (int i{ 0 }; i < rows; i++)
			elements[i] = new T[cols];
	}
	~Table() {
		for (int i{ 0 }; i < rows; i++)
			delete[] elements[i];
		delete[] elements;
		elements = nullptr;
	}

	const T* operator[](const int row) const {
		if ( row < 0 || row >= rows ) 
			throw std::runtime_error("Некорректный индекс");
		return elements[row];
	}
	T* operator[](const int row) {
		if ( row < 0 || row >= rows ) 
			throw std::runtime_error("Некорректный индекс");
		return elements[row];
	}

	int Size() const {
		return rows * cols;
	}
};