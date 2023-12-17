//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_CONSOLELOGGER_H
#define CXXLEARNING_CONSOLELOGGER_H

#include "iostream"
#include "AbstractLogger.h"

class ConsoleLogger : public AbstractLogger {
public:
    explicit ConsoleLogger(LoggerLevel level) : AbstractLogger(level) {}

private:
    void Write(std::string message) override {
        std::cout << "Standard Console::Logger: " << message << std::endl;
    }
};

#endif //CXXLEARNING_CONSOLELOGGER_H
