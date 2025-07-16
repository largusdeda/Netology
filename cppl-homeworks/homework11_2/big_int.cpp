#include "big_int.h"
#include <stdexcept>
#include <string>
#include <memory>
#include <iostream>

big_integer::big_integer() {
	value = "0";
}

big_integer::big_integer(std::string num) {
	value = num.length() == 0 ? "0" : num;

	int zeros_count{ 0 };
	while (value[zeros_count] == '0' && value.length() - zeros_count > 1)
		zeros_count++;
	value = value.substr(zeros_count);

	for (int i{ 0 }; i < value.length(); i++)
		if (value[i] < '0' || value[i] > '9')
			throw std::runtime_error(value + " is not a number");
}

big_integer::big_integer(const big_integer& other) {
	value = other.value;
}

big_integer::big_integer(big_integer&& other) noexcept {
	value = std::move(other.value);
}

big_integer& big_integer::operator=(const big_integer& other) {
	if (this != &other)
		value = other.value;

	return *this;
}

big_integer& big_integer::operator=(big_integer&& other) noexcept {
	if (this != &other)
		value = std::move(other.value);

	return *this;
}

big_integer big_integer::operator+(const big_integer& other) {
	size_t len1{ value.length() };
	size_t len2{ other.value.length() };

	size_t length{ 1 + std::max(len1, len2) };
	auto res = std::make_unique<char[]>(length + 1);

	res[length - 1] = res[length] = '\0';

	for (size_t i = 0; i < length - 1; i++) {
		size_t j = length - 1 - i;
		res[j] += ((i < len2) ? (other.value[len2 - 1 - i] - '0') : 0) + ((i < len1) ? (value[len1 - 1 - i] - '0') : 0);
		res[j - 1] = res[j] / 10;
		res[j] = res[j] % 10 + '0';
	}
	res[0] += '0';

	return big_integer(res.get());
}

big_integer big_integer::operator*(const big_integer& other) {
	if (value == "0" || other.value == "0")
		return big_integer();

	size_t len1{ value.length() };
	size_t len2{ other.value.length() };

	size_t length{ len1 + len2 + 1 };

	if (length < 9) {
		long res = stol(value) * stol(other.value);
		return big_integer(std::to_string(res));
	}
	else {
		auto a = std::make_unique<int[]>(length);
		auto b = std::make_unique<int[]>(length);

		auto res = std::make_unique<char[]>(length + 1);
		res[length] = '\0';

		for (size_t i = 0; i < length; i++) {
			a[i] = (i < len1) ? (value[len1 - 1 - i] - '0') : 0;
			b[i] = (i < len2) ? (other.value[len2 - 1 - i] - '0') : 0;
			res[i] = 0;
		}

		for (size_t i = 0; i < len1; i++) {
			for (size_t j = 0; j < len2; j++) {
				res[length - 1 - (i + j)] += a[i] * b[j];
				res[length - 1 - (i + j + 1)] += res[length - 1 - (i + j)] / 10;
				res[length - 1 - (i + j)] %= 10;
			}
		}

		for (size_t i = 0; i < length; i++)
			res[length - 1 - i] += '0';

		return big_integer(res.get());
	}
}

big_integer big_integer::operator*(int other) {
	auto tmp = big_integer(std::to_string(other));
	return *this * tmp;
}

std::ostream& operator<<(std::ostream& stream, const big_integer& num) {
	return stream << num.value;
}