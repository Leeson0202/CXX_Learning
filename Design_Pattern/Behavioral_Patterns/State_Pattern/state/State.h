//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_STATE_H
#define CXXLEARNING_STATE_H

class State {
public:
    virtual void doAction(void *context) = 0;
    virtual std::string toString() = 0;
};

#endif //CXXLEARNING_STATE_H
