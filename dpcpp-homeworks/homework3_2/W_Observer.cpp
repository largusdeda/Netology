#include "W_Observer.h"

void  WarningObserver::onWarning(const std::string& message) {
    std::cout << "Warning: " << message << std::endl << std::endl;
}