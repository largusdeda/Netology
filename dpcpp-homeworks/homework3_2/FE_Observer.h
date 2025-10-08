#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

#include "Observer.h"

class FatalErrorObserver : public Observer {

public:
    explicit FatalErrorObserver(const std::string& filePath);
    void onFatalError(const std::string& message) override;

private:
    std::string filePath_;

};