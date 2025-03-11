#pragma once
#ifdef FIGURESLIB_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif
#include "figure.h"

namespace Figures {
	class Quadrangle : public Figure {
	protected:
		int a, b, c, d, A, B, C, D;
	public:
		Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);

		std::string get_name() override;
		std::string get_sides() override;
		std::string get_angles() override;
	};
}