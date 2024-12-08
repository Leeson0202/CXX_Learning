//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_STARTSTATE_H
#define CXXLEARNING_STARTSTATE_H

#include "iostream"
#include "State.h"

using namespace std;

class StartState : public State {
public:
    void doAction(void *context) override {
        cout << "StartState: doAction" << endl;
        ((Context *)context)->setState(this);
    }

    string toString() override {
        return "StartState";
    }

};

#endif //CXXLEARNING_STARTSTATE_H
