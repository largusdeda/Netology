#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        auto now{ std::chrono::system_clock::now() };
        std::time_t time{ std::chrono::system_clock::to_time_t(now) };

        std::cout << std::ctime(&time) << message << std::endl << std::endl;
    }
};

class FileLogCommand : public LogCommand {
public:
    explicit FileLogCommand(const std::string& filePath) : filePath_(filePath) {}

    void print(const std::string& message) override {
        auto now{ std::chrono::system_clock::now() };
        std::time_t time{ std::chrono::system_clock::to_time_t(now) };

        std::ofstream file(filePath_, std::ios::app);
        file << std::ctime(&time) << message << std::endl << std::endl;
        file.close();
    }

private:
    std::string filePath_;
};

void print(LogCommand& command, const std::string& message) {
    command.print(message);
};

int main() {
    ConsoleLogCommand consoleCommand;
    print(consoleCommand, "Console log message.");

    FileLogCommand fileCommand("log.txt");
    print(fileCommand, "File log message.");

    return EXIT_SUCCESS;
}