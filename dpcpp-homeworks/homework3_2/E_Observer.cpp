#include "E_Observer.h"

ErrorObserver::ErrorObserver(const std::string& filePath) : filePath_(filePath) 
{}

void ErrorObserver::onError(const std::string& message) {
    auto now{ std::chrono::system_clock::now() };
    std::time_t time{ std::chrono::system_clock::to_time_t(now) };

    std::ofstream file(filePath_, std::ios::app);
    file << std::ctime(&time) << "An error occured:\n" << message << std::endl << std::endl;
    file.close();
}