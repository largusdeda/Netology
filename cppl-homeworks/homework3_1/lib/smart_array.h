#pragma once

class smart_array {

private:
	int *ptr;
	size_t size;
	size_t capacity;

public:
	smart_array(const int n);
	void add_element(const int el);
	int get_element(const int index);
	~smart_array();

};