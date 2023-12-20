//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_CARETAKER_H
#define CXXLEARNING_CARETAKER_H

#include "Memento.h"
#include "vector"

using namespace std;

class CareTaker {
private:
    vector<Memento *> mementoList = {};
public:
    void add(Memento *me) {
        mementoList.push_back(me);
    }

    Memento *get(int idx) {
        if (idx < mementoList.size()) return mementoList[idx];
        return nullptr;
    }

};

#endif //CXXLEARNING_CARETAKER_H
