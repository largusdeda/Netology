#include "E_Handler.h"

ErrorHandler::ErrorHandler(const std::string& filePath) : filePath_(filePath) 
{}

void ErrorHandler::handle(const LogMessage& message) {
    if (message.type() == Type::ERROR) {
        auto now{ std::chrono::system_clock::now() };
        std::time_t time{ std::chrono::system_clock::to_time_t(now) };

        std::ofstream file(filePath_, std::ios::app);
        file << std::ctime(&time) << message.message() << std::endl << std::endl;
        file.close();
    }
    else if (next_) {
        next_->handle(message);
    }
}