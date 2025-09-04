#include "ConsoleParam.h"

void ConsoleParameter::SetColor(int text, int background) {
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void ConsoleParameter::SetPosition(int x, int y) {
    COORD point{};
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(hStdOut, point);
}