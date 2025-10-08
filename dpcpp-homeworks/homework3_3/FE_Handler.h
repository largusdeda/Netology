#pragma once

#include <stdexcept>

#include "Handler.h"
#include "LogMessage.h"

class FatalErrorHandler : public Handler {

public:
    void handle(const LogMessage& message) override;

};