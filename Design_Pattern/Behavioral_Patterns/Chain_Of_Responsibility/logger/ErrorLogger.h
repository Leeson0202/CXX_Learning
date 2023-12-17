//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_ERRORLOGGER_H
#define CXXLEARNING_ERRORLOGGER_H

#include "iostream"
#include "AbstractLogger.h"

class ErrorLogger : public AbstractLogger {
public:
    explicit ErrorLogger(LoggerLevel level) : AbstractLogger(level) {}

private:
    void Write(std::string message) override {
        std::cout << "Standard ERROR::Logger: " << message << std::endl;
    }
};

#endif //CXXLEARNING_ERRORLOGGER_H
