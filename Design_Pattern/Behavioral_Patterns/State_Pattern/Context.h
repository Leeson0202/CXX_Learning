//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_CONTEXT_H
#define CXXLEARNING_CONTEXT_H

#include "state/State.h"

class Context {
private:
    State *m_state = nullptr;
public:
    void setState(State *state) {
        m_state = state;
    }

    State *getState() {
        return m_state;
    }

};

#endif //CXXLEARNING_CONTEXT_H
