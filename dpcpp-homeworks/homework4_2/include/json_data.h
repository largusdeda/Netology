#pragma once

#include <string>

#include "printable.h"

class JSONData : public JSONPrintable {

public:
    explicit JSONData(std::string data);
    std::string printAsJSON() const override;

private:
    std::string data_;

};