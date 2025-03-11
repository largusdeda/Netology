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
		FIGURES_API Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);

		FIGURES_API std::string get_name() override;
		FIGURES_API std::string get_sides() override;
		FIGURES_API std::string get_angles() override;
	};
}