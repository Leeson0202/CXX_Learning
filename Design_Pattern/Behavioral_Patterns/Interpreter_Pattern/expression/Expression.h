//
// Created by ￼ Leeson on 2023/12/19.
//

#ifndef CXXLEARNING_EXPRESSION_H
#define CXXLEARNING_EXPRESSION_H
#include "iostream"

class Expression {
public:
    virtual bool interpret(std::string context) = 0;
};


#endif //CXXLEARNING_EXPRESSION_H
