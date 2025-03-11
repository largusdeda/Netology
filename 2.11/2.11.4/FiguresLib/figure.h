#pragma once
#ifdef FIGURESLIB_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif
#include <string>

namespace Figures {
	class Figure {
	protected:
		std::string name = "Фигура";
	public:
		FIGURES_API virtual std::string get_name();
		FIGURES_API virtual std::string get_sides();
		FIGURES_API virtual std::string get_angles();
	};
}