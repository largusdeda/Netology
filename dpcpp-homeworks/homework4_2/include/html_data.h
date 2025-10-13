#pragma once

#include <string>

#include "printable.h"

class HTMLData : public HTMLPrintable {

public:
    explicit HTMLData(std::string data);
    std::string printAsHTML() const override;

private:
    std::string data_;

};