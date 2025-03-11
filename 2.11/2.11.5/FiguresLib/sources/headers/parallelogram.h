#pragma once
#ifdef FIGURESLIB_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif
#include "quadrangle.h"

namespace Figures {
	class Parallelogram : public Quadrangle {
	public:
		Parallelogram(int a, int b, int A, int B);
	};
}