//
// Created by ￼ Leeson on 2023/12/21.
//

#ifndef CXXLEARNING_SUBSTRATEGY_H
#define CXXLEARNING_SUBSTRATEGY_H

#include "Strategy.h"

class SubStrategy : public Strategy {
    int doOperation(int a, int b) override {
        return a - b;
    }
};

#endif //CXXLEARNING_SUBSTRATEGY_H
