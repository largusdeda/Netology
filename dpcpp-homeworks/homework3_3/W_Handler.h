#pragma once

#include <iostream>

#include "Handler.h"
#include "LogMessage.h"

class WarningHandler : public Handler {

public:
    void handle(const LogMessage& message) override;

};