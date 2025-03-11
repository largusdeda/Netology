#pragma once
#ifdef FIGURESLIB_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif
#include "triangle.h"

namespace Figures {
	class Right_triangle : public Triangle {
	public:
		Right_triangle(int a, int b, int c, int A, int B);
	};
}