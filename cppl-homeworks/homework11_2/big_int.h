#pragma once
#include <string>

class big_integer {

private:
	std::string value;

public:
	big_integer();
	big_integer(std::string num);

	big_integer(const big_integer& other);
	big_integer(big_integer&& other) noexcept;

	big_integer& operator=(const big_integer& other);
	big_integer& operator=(big_integer&& other) noexcept;

	big_integer operator+(const big_integer& other);
	big_integer operator*(const big_integer& other);
	big_integer operator*(int other);

	friend std::ostream& operator<<(std::ostream& stream, const big_integer& num);
};