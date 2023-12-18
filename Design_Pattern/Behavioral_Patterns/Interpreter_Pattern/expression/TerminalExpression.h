//
// Created by ￼ Leeson on 2023/12/19.
//

#ifndef CXXLEARNING_TERMINALEXPRESSION_H
#define CXXLEARNING_TERMINALEXPRESSION_H

#include "iostream"
#include "Expression.h"

class TerminalExpression : public Expression {
public:
    explicit TerminalExpression(const char *data) {
        this->data = data;
    }

    bool interpret(std::string context) override {
        return context.find(data) != -1;
    }

private:
    std::string data;
};

#endif //CXXLEARNING_TERMINALEXPRESSION_H
