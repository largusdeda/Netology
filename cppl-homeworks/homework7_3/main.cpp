#include <iostream>
#include "My_Vector_Templ.h"

int main() {
#ifdef _WIN32
	setlocale(LC_ALL, "rus");
#endif

	My_Vector<int> vec1(5);

	std::cout << "vec1.size: " << vec1.size() << std::endl;
	std::cout << "vec1.capacity(): " << vec1.capacity() << std::endl;

	vec1.push_back(1);
	vec1.push_back(2);

	std::cout << "vec1.size: " << vec1.size() << std::endl;
	std::cout << "vec1.capacity(): " <<  vec1.capacity() << std::endl;

	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(5);
	vec1.push_back(6);

	std::cout << "vec1.size: " << vec1.size() << std::endl;
	std::cout << "vec1.capacity(): " << vec1.capacity() << std::endl;

	vec1.push_back(7);
	vec1.push_back(8);
	
	std::cout << "vec1.size: " << vec1.size() << std::endl;
	std::cout << "vec1.capacity(): " << vec1.capacity() << std::endl;

	std::cout << "vec1.at(5): " << vec1.at(5) << std::endl;
	try {
		std::cout << vec1.at(100) << std::endl;
	}
	catch (const std::out_of_range &ex) {
		std::cout << "vec1.at(100): ";
		std::cout << ex.what();
	}

	My_Vector<std::string> vec2(5);
	vec2.push_back("aa");
	vec2.push_back("bb");
	vec2.push_back("ab");

	My_Vector<std::string> vec3(vec2);
	std::cout << vec3.size() << std::endl;
	My_Vector<std::string> vec4(std::move(vec3));
	std::cout << vec3.size() << " " << vec4.size() << std::endl;
	vec3 = std::move(vec4);
	std::cout << vec3.size() << " " << vec4.size() << std::endl;

	return EXIT_SUCCESS;
}