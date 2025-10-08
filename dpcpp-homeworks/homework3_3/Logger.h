#pragma once

#include <memory>

#include "LogMessage.h"
#include "Handler.h"
#include "FE_Handler.h"
#include "E_Handler.h"
#include "W_Handler.h"
#include "U_Handler.h"

class Logger {

public:
    Logger();
    void log(const LogMessage& message) const;

private:
    std::shared_ptr<Handler> fatalErrorHandler_;
    std::shared_ptr<Handler> errorHandler_;
    std::shared_ptr<Handler> warningHandler_;
    std::shared_ptr<Handler> unknownHandler_;

};