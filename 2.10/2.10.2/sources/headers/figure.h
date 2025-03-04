#pragma once
#include <string>

class Figure {
protected:
	std::string name = "������";
public:
	virtual std::string get_name();
	virtual std::string get_sides();
	virtual std::string get_angles();
};