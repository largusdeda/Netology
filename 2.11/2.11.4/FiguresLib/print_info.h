#pragma once
#ifdef FIGURESLIB_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif
#include "figure.h"

namespace Figures {
	FIGURES_API void print_info(Figure *f);
}