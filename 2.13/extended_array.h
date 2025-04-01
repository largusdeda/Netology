#pragma once
#include <utility>
#include <initializer_list>
#include <deque>
#include <algorithm>
#include <iostream>

template <typename T>
class ExtArray
{
private:
	//std::vector<T> extended_array;
	std::deque<T> extended_array;
	size_t _size;
public:
	ExtArray(std::initializer_list<T> l) : extended_array(l)
	{
		_size = l.size();
	}

	ExtArray(int size) : _size(size)
	{
		extended_array.resize(_size);
	}

	T& operator[](size_t index)
	{
		return extended_array[index];
	}

	size_t size()
	{
		return _size;
	}

	double mean()
	{
		double sum = 0;
		for (size_t i = 0; i < _size; i++)
		{
			sum += extended_array[i];
		}
		return sum / _size;
	}

	double mean(int begin, int end)
	{
		if (begin > end || begin < 0 || end > (extended_array.size() - 1)) {
			throw std::invalid_argument("invalid argument");
		}
		double sum = 0;
		for (size_t i = begin; i <= end; i++)
		{
			sum += extended_array[i];
		}
		return sum / (end - begin + 1);
	}

	double median()
	{
		std::deque<T> temp_array;
		std::copy(extended_array.begin(), extended_array.end(), back_inserter(temp_array));
		std::sort(temp_array.begin(), temp_array.end());
		if (_size % 2 == 1)
		{
			return temp_array[_size / 2];
		}
		else
		{
			return static_cast<double>(temp_array[(_size / 2) - 1] + temp_array[_size / 2]) / 2;
		}
	}

	std::pair<T, int> mode()
	{
		T max = extended_array[0], cmax = 0, rmax = 0;
		for (int i = 0; i < _size; i++) 
		{
			if (cmax > rmax) 
			{
				rmax = cmax;
				max = extended_array[i - 1];
			}
			cmax = 0;
			for (int j = i; j < _size; j++)
			{
				if (extended_array[j] == extended_array[i])
				{
					cmax++;
				}
			}
		}
		return std::pair<T, int>(max, rmax);
	}

	int checkSum() 
	{
		if (typeid(extended_array[0]) != typeid(int) && typeid(extended_array[0]) != typeid(bool)) {
			throw std::bad_typeid();
		}
		int count{ 0 };
		for (auto& el : extended_array) {
			if (static_cast<bool>(el) == true) {
				count++;
			}
		}
		return count;
	}
};
