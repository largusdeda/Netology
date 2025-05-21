#pragma once

class smart_array {

private:
	int *ptr;
	size_t size;
	size_t capacity;

public:
	smart_array(const int n);
	smart_array(const smart_array& new_arr);
	smart_array& operator=(const smart_array& new_arr);
	void add_element(const int el);
	int get_element(const int index);
	~smart_array();

};