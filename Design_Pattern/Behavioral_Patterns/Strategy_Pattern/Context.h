//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_CONTEXT_H
#define CXXLEARNING_CONTEXT_H

#include "strategy/Strategy.h"

class Context {
private:
    Strategy *m_strategy = nullptr;
public:
    Context(Strategy *strategy) : m_strategy(strategy) {}

    int executeStrategy(int a, int b) {
        return m_strategy->doOperation(a, b);
    }

};

#endif //CXXLEARNING_CONTEXT_H
