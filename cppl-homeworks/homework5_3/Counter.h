#pragma once

struct Counter {
	int sum{ 0 };
	int count{ 0 };

	void operator()(int num);
	int get_sum() const;
	int get_count() const;
};