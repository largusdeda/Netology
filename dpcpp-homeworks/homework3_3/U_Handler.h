#pragma once

#include <stdexcept>

#include "Handler.h"
#include "LogMessage.h"

class UnknownHandler : public Handler {

public:
    void handle(const LogMessage& message) override;

};