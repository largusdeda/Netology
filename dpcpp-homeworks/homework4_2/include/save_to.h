#pragma once

#include <fstream>

#include "printable.h"

void saveTo(std::ofstream& file, const TextPrintable& printable);
void saveTo(std::ofstream& file, const HTMLPrintable& printable);
void saveTo(std::ofstream& file, const JSONPrintable& printable);