//
// Created by ￼ Leeson on 2023/12/21.
//

#ifndef CXXLEARNING_ADDSTRATEGY_H
#define CXXLEARNING_ADDSTRATEGY_H

#include "Strategy.h"

class AddStrategy : public Strategy {
    int doOperation(int a, int b) override {
        return a + b;
    }
};

#endif //CXXLEARNING_ADDSTRATEGY_H
