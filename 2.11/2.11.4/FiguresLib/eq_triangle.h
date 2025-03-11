#pragma once
#ifdef FIGURESLIB_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif
#include "isos_triangle.h"

namespace Figures {
	class Equilateral_triangle : public Isosceles_triangle {
	public:
		FIGURES_API Equilateral_triangle(int a);
	};
}