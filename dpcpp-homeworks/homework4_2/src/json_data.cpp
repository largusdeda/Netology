﻿#include "json_data.h"

JSONData::JSONData(std::string data) : data_(std::move(data)) {}

std::string JSONData::printAsJSON() const {
    return "{ \"data\": \"" + data_ + "\" }";
}