#pragma once

#include <fstream>
#include <chrono>
#include <ctime>

#include "Handler.h"
#include "LogMessage.h"

class ErrorHandler : public Handler {

public:
    explicit ErrorHandler(const std::string& filePath);
    void handle(const LogMessage& message) override;

private:
    std::string filePath_;

};