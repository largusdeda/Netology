#pragma once

#include <memory>

#include "LogMessage.h"

class Handler {

public:
    virtual void handle(const LogMessage& message) = 0;
    void setNext(std::shared_ptr<Handler> next);

protected:
    std::shared_ptr<Handler> next_;

};
