#include <iostream>
#include <string>
#include <numeric>

class Fraction {
	private:
		int numerator_;
		int denominator_;

	public:
		Fraction(int numerator, int denominator) {
			if (denominator == 0)
				throw std::runtime_error("zero denominator");
			numerator_ = numerator;
			denominator_ = denominator;
		}

	Fraction operator+(Fraction other) {
		return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_).Reduce();
	}
	Fraction operator+(int other) {
		return Fraction(numerator_ + other * denominator_, denominator_).Reduce();
	}
	Fraction operator-(Fraction other) {
		return *this + Fraction(-other.numerator_, other.denominator_);
	}
	Fraction operator-(int other) {
		return *this + (-other);
	}
	Fraction operator*(Fraction other) {
		return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_).Reduce();
	}
	Fraction operator/(Fraction other) {
		return *this * Fraction(other.denominator_, other.numerator_);
	}
	Fraction& operator++() {
		*this = *this + 1;
		return *this;
	}
	Fraction operator++(int) {
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction& operator--() {
		*this = *this - 1;
		return *this;
	}
	Fraction operator--(int) {
		Fraction temp = *this;
		--(*this);
		return temp;
	}

	bool operator==(Fraction other) {
		return numerator_ * other.denominator_ == other.numerator_ * denominator_;
	}
	bool operator!=(Fraction other) {
		return !(*this == other);
	}
	bool operator>(Fraction other) {
		return numerator_ * other.denominator_ > other.numerator_ * denominator_;
	}
	bool operator<(Fraction other) {
		return other > *this;
	}
	bool operator>=(Fraction other) {
		return !(*this < other);
	}
	bool operator<=(Fraction other) {
		return !(*this > other);
	}

	Fraction Reduce() {
		int n{std::gcd(numerator_, denominator_)};
		return Fraction(numerator_ / n, denominator_ / n);
	}
	std::string Print() {
		return std::to_string(numerator_) + "/" + std::to_string(denominator_) + "\n";
	}
};

int main() {
	setlocale(LC_ALL, "rus");

	int numerator{}, denominator{};
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator;
	Fraction f1(numerator, denominator);

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator;
	Fraction f2(numerator, denominator);

	Fraction sum = f1 + f2;
	std::cout << "f1 + f2 = " << sum.Print() << std::endl;

	Fraction diff = f1 - f2;;
	std::cout << "f1 - f2 = " << diff.Print() << std::endl;

	Fraction mult = f1 * f2;
	std::cout << "f1 * f2 = " << mult.Print() << std::endl;

	Fraction div = f1 / f2;
	std::cout << "f1 / f2 = " << div.Print() << std::endl;

	Fraction preinc_mult = ++f1 * f2;
	std::cout << "++f1 * f2 = " << preinc_mult.Print() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.Print() << std::endl;

	Fraction postdec_mult = f1-- * f2;
	std::cout << "f1-- * f2 = " << postdec_mult.Print() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.Print() << std::endl;
}