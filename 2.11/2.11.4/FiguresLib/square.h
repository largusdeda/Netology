#pragma once
#ifdef FIGURESLIB_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif
#include "rectangle.h"

namespace Figures {
	class Square : public Rectangle {
	public:
		FIGURES_API Square(int a);
	};
}