#include <iostream>
#include <exception>

#include "Logger.h"

int main() {
    Logger logger;

    try {
        logger.log(LogMessage(Type::WARNING, "Warning message."));
        logger.log(LogMessage(Type::ERROR, "Error message."));
        logger.log(LogMessage(Type::FATAL_ERROR, "Fatal error message."));
        logger.log(LogMessage(Type::UNKNOWN, "Unknown message."));
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}