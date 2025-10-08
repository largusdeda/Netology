#include "Logger.h"

void Logger::addObserver(std::weak_ptr<Observer> observer) {
	observers_.push_back(observer);
}

void Logger::warning(const std::string& message) const {
    for (auto& observer : observers_) {
        if (auto p = observer.lock()) {
            p->onWarning(message);
        }
    }
}

void Logger::error(const std::string& message) const {
    for (auto& observer : observers_) {
        if (auto p = observer.lock()) {
            p->onError(message);
        }
    }
}

void Logger::fatalError(const std::string& message) const {
    for (auto& observer : observers_) {
        if (auto p = observer.lock()) {
            p->onFatalError(message);
        }
    }
}