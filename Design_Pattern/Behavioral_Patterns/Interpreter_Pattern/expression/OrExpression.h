//
// Created by ￼ Leeson on 2023/12/19.
//

#ifndef CXXLEARNING_OREXPRESSION_H
#define CXXLEARNING_OREXPRESSION_H

#include "iostream"
#include "Expression.h"

class OrExpression : public Expression {
public:
    OrExpression(Expression *e1, Expression *e2) : e1(e1), e2(e2) {}

    bool interpret(std::string context) override {
        return e1->interpret(context) || e2->interpret(context);
    }

private:
    Expression *e1;
    Expression *e2;
};

#endif //CXXLEARNING_OREXPRESSION_H
