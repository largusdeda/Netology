#include "Logger.h"

Logger::Logger() {
    fatalErrorHandler_ = std::make_shared<FatalErrorHandler>();
    errorHandler_ = std::make_shared<ErrorHandler>("error_log.txt");
    warningHandler_ = std::make_shared<WarningHandler>();
    unknownHandler_ = std::make_shared<UnknownHandler>();

    fatalErrorHandler_->setNext(errorHandler_);
    errorHandler_->setNext(warningHandler_);
    warningHandler_->setNext(unknownHandler_);
}

void Logger::log(const LogMessage& message) const {
    fatalErrorHandler_->handle(message);
}