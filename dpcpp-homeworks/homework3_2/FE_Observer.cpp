#include "FE_Observer.h"

FatalErrorObserver::FatalErrorObserver(const std::string& filePath) : filePath_(filePath) 
{}

void FatalErrorObserver::onFatalError(const std::string& message) {
    auto now{ std::chrono::system_clock::now() };
    std::time_t time{ std::chrono::system_clock::to_time_t(now) };

    std::cout << std::ctime(&time) << "A fatal error occured:\n" << message << std::endl << std::endl;

    std::ofstream file(filePath_, std::ios::app);
    file << std::ctime(&time) << "A fatal error occured:\n" << message << std::endl << std::endl;
    file.close();
}