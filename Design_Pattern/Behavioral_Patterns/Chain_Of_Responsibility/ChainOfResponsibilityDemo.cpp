//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"
#include "logger/AbstractLogger.h"
#include "logger/ConsoleLogger.h"
#include "logger/ErrorLogger.h"

AbstractLogger *getLoggerChain() {
    auto chain = new ConsoleLogger(INFO);
    auto error = new ErrorLogger(ERROR);
    chain->setNextLogger(error);
    return chain;

}

int main() {
    auto loggerChain = getLoggerChain();
    loggerChain->logMessage(INFO, "Information");
    loggerChain->logMessage(ERROR, "Killed");
    return 0;
}