//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_ABSTRACTLOGGER_H
#define CXXLEARNING_ABSTRACTLOGGER_H

#include "iostream"

enum LoggerLevel {
    INFO = 1,
    DEBUG,
    ERROR
};

class AbstractLogger {
public:
    AbstractLogger() = default;

    explicit AbstractLogger(LoggerLevel loggerLevel) : level(loggerLevel) {}

    void setNextLogger(AbstractLogger *logger) {
        nextLogger = logger;
    }

    void logMessage(LoggerLevel loggerLevel, std::string message) {
        if (level <= loggerLevel) {
            Write(message);
        }
        if (nextLogger != nullptr) {
            nextLogger->logMessage(loggerLevel, message);
        }

    }

private:
    virtual void Write(std::string message) = 0;

    LoggerLevel level;
    AbstractLogger *nextLogger;

};

#endif //CXXLEARNING_ABSTRACTLOGGER_H
