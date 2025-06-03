#include <iostream>
#include <vector>
#include <algorithm>

class Sum {
private:
	int sum{ 0 };
public:
	void operator()(int n) { 
		if (0 == n % 3) 
			sum += n; 
	}
	
	int getSum() const {
		return sum;
	}
};

class Count {
private:
	int count{ 0 };
public:
	void operator()(int n) { 
		if (0 == n % 3) 
			count++; 
	}
	
	int getCount() const {
		return count;
	}
};

int get_sum(std::vector<int> &v) {
	Sum s = std::for_each(v.cbegin(), v.cend(), Sum());
	return s.getSum();
}

int get_count(std::vector<int> &v) {
	Count c = std::for_each(v.cbegin(), v.cend(), Count());
	return c.getCount();
}

int main() {
	std::vector<int> vec = { 4, 1, 3, 6, 25, 54 };

	std::cout << "[IN]: ";
	for (auto& i : vec)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "[OUT]: get_sum() = ";
	std::cout << get_sum(vec) << std::endl;

	std::cout << "[OUT]: get_count() = ";
	std::cout << get_count(vec) << std::endl;

	return 0;
}