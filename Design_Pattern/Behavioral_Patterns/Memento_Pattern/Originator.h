//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_ORIGINATOR_H
#define CXXLEARNING_ORIGINATOR_H

#include "iostream"
#include "Memento.h"

using namespace std;

class Originator {
private:
    string m_state = "";

public:
    Originator() {};

    explicit Originator(string state) : m_state(state) {}

    void setState(string state) {
        m_state = state;
    }

    string &getState() {
        return m_state;
    }

    Memento *saveStateToMemento() {
        return new Memento(m_state);
    }

    void getStateFromMemento(Memento *me) {
        m_state = me->getState();
    }


};

#endif //CXXLEARNING_ORIGINATOR_H
