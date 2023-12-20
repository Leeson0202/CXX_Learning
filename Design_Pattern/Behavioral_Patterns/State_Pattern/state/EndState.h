//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_ENDSTATE_H
#define CXXLEARNING_ENDSTATE_H

#include "iostream"
#include "State.h"

using namespace std;

class EndState : public State {
public:
    void doAction(void *context) override {
        cout << "EndState: doAction" << endl;
        ((Context *) context)->setState(this);
    }

    string toString() override {
        return "EndState";
    }

};

#endif //CXXLEARNING_ENDSTATE_H
