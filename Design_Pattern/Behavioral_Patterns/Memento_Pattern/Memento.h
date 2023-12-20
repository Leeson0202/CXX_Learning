//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_MEMENTO_H
#define CXXLEARNING_MEMENTO_H

#include "iostream"

using namespace std;

class Memento {
private:
    string m_state;
public:
    Memento() = default;

    explicit Memento(string state) : m_state(state) {}

    string getState() { return m_state; }

    Memento *saveStateToMemento() {
        return new Memento(m_state);
    }

    void getStateFromMemento(Memento *me) {
        m_state = me->getState();
    }
};

#endif //CXXLEARNING_MEMENTO_H
