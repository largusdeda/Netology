#pragma once

#include <string>

enum class Type {
    WARNING,
    ERROR,
    FATAL_ERROR,
    UNKNOWN
};

class LogMessage {

public:
    LogMessage(Type type, const std::string& message);
    Type type() const;
    const std::string& message() const;

private:
    Type type_;
    std::string message_;

};