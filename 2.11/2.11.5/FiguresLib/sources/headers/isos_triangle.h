#pragma once
#ifdef FIGURESLIB_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif
#include "triangle.h"

namespace Figures {
	class Isosceles_triangle : public Triangle {
	public:
		Isosceles_triangle(int a, int b, int A, int B);
	};
}