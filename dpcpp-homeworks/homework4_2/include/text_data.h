#pragma once

#include <string>

#include "printable.h"

class TextData : public TextPrintable {

public:
    explicit TextData(std::string data);
    std::string printAsText() const override;

private:
    std::string data_;

};
