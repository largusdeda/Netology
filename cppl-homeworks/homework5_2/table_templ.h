#pragma once

#include <stdexcept>

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
	Table(Table &t) {
		elements = new T*[t.rows];
		for (int i{ 0 }; i < t.rows; i++)
			elements[i] = new T[t.cols];
		rows = t.rows;
		cols = t.cols;
		for (int i{ 0 }; i < rows; i++)
			for (int j{ 0 }; j < cols; j++)
				elements[i][j] = t[i][j];
	}

	~Table() {
		for (int i{ 0 }; i < rows; i++)
			delete[] elements[i];
		delete[] elements;
		elements = nullptr;
	}

	Table& operator=(const Table &t2) {
		if (this != &t2) {
			for (int i{ 0 }; i < rows; i++)
				delete[] elements[i];
			delete[] elements;

			elements = new T*[t2.rows];
			for (int i{ 0 }; i < t2.rows; i++)
				elements[i] = new T[t2.cols];
			rows = t2.rows;
			cols = t2.cols;

			for (int i{ 0 }; i < rows; i++)
				for (int j{ 0 }; j < cols; j++)
					elements[i][j] = t2[i][j];
		}

		return *this;
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
