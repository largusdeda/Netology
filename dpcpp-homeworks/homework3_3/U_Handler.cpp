#include "U_Handler.h"

void UnknownHandler::handle(const LogMessage& message) {
    if (message.type() == Type::UNKNOWN) {
        throw std::runtime_error("Unknown message: " + message.message());
    }
    else if (next_) {
        next_->handle(message);
    }
}