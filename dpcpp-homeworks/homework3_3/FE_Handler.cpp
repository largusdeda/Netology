#include "FE_Handler.h"

void FatalErrorHandler::handle(const LogMessage& message) {
    if (message.type() == Type::FATAL_ERROR) {
        throw std::runtime_error("Fatal Error: " + message.message());
    }
    else if (next_) {
        next_->handle(message);
    }
}