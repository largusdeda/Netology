#pragma once

#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

#include "Observer.h"

class ErrorObserver : public Observer {

public:
    explicit ErrorObserver(const std::string& filePath);
    void onError(const std::string& message) override;

private:
    std::string filePath_;

};