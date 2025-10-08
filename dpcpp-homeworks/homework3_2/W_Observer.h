﻿#pragma once

#include <iostream>

#include "Observer.h"

class WarningObserver : public Observer {

public:
    void onWarning(const std::string& message) override;

};