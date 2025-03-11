#pragma once
#ifdef FIGURESLIB_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif
#include "parallelogram.h"

namespace Figures {
	class Rhombus : public Parallelogram {
	public:
		Rhombus(int a, int A, int B);
	};
}