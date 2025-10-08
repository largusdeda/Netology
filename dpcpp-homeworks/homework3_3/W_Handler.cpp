#include "W_Handler.h"

void WarningHandler::handle(const LogMessage& message) {
    if (message.type() == Type::WARNING) {
        std::cout << "Warning: " << message.message() << std::endl << std::endl;
    }
    else if (next_) {
        next_->handle(message);
    }
}