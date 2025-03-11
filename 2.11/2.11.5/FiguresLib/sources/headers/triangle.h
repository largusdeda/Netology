#pragma once
#ifdef FIGURESLIB_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif
#include "figure.h"

namespace Figures {
	class Triangle : public Figure {
	protected:
		int a, b, c, A, B, C;
	public:
		Triangle(int a, int b, int c, int A, int B, int C);

		std::string get_name() override;

		std::string get_sides() override;

		std::string get_angles() override;
	};
}