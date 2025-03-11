#pragma once
#ifdef FIGURESLIB_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif
#include "parallelogram.h"

namespace Figures {
	class Rectangle : public Parallelogram {
	public:
		Rectangle(int a, int b);
	};
}