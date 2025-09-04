#pragma once
#include <Windows.h>

class ConsoleParameter {

private:
	static inline HANDLE hStdOut{ GetStdHandle(STD_OUTPUT_HANDLE) };

public:
	void SetColor(int text, int background);
	void SetPosition(int x, int y);
};