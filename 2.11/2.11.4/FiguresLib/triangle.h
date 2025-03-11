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
		FIGURES_API Triangle(int a, int b, int c, int A, int B, int C);

		FIGURES_API std::string get_name() override;
		FIGURES_API std::string get_sides() override;
		FIGURES_API std::string get_angles() override;
	};
}