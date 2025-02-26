#include <iostream>
#include "triangle.h"
#include "right_triangle.h"
#include "isos_triangle.h"
#include "eq_triangle.h"
#include "quadrangle.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "rhombus.h"
#include "square.h"
#include "print_info.h"
#include "invalid_figure_error.h"


int main() {
	setlocale(LC_ALL, "rus");

	//Треугольник
	try {
		Triangle triangle(10, 20, 30, 50, 60, 70);
		print_info(&triangle);
		std::cout << "создан\n" << std::endl;
	}
	catch (const invalid_figure_error &ex) {
		std::cout << "Треугольник: " << ex.what() << std::endl;
	}

	//Прямоугольный треугольник
	try {
		Right_triangle right_triangle(10, 20, 30, 50, 60);
		print_info(&right_triangle);
		std::cout << "создан\n" << std::endl;
	}
	catch (const invalid_figure_error &ex) {
		std::cout << "Прямоугольный треугольник: " << ex.what() << std::endl;
	}

	//Равнобедренный треугольник
	try {
		Isosceles_triangle isosceles_triangle(10, 20, 50, 60);
		print_info(&isosceles_triangle);
		std::cout << "создан\n" << std::endl;
	}
	catch (const invalid_figure_error &ex) {
		std::cout << "Равнобедренный треугольник: " << ex.what() << std::endl;
	}

	//Равносторонний треугольник
	try {
		Equilateral_triangle equilateral_triangle(30);
		print_info(&equilateral_triangle);
		std::cout << "создан\n" << std::endl;
	}
	catch (const invalid_figure_error &ex) {
		std::cout << "Равносторонний треугольник: " << ex.what() << std::endl;
	}

	//Четырёхугольник
	try {
		Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
		print_info(&quadrangle);
		std::cout << "создан\n" << std::endl;
	}
	catch (const invalid_figure_error &ex) {
		std::cout << "Четырёхугольник: " << ex.what() << std::endl;
	}

	//Параллелограм
	try {
		Parallelogram parallelogram(20, 30, 30, 40);
		print_info(&parallelogram);
		std::cout << "создан\n" << std::endl;
	}
	catch (const invalid_figure_error &ex) {
		std::cout << "Параллелограм: " << ex.what() << std::endl;
	}

	//Прямоугольник
	try {
		Rectangle rectangle(10, 20);
		print_info(&rectangle);
		std::cout << "создан\n" << std::endl;
	}
	catch (const invalid_figure_error &ex) {
		std::cout << "Прямоугольник: " << ex.what() << std::endl;
	}

	//Ромб
	try {
		Rhombus rhombus(30, 30, 40);
		print_info(&rhombus);
		std::cout << "создан\n" << std::endl;
	}
	catch (const invalid_figure_error &ex) {
		std::cout << "Ромб: " << ex.what() << std::endl;
	}

	//Квадрат
	try {
		Square square(20);
		print_info(&square);
		std::cout << "создан\n" << std::endl;
	}
	catch (const invalid_figure_error &ex) {
		std::cout << "Квадрат: " << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
