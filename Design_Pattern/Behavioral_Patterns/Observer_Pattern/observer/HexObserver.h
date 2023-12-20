//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_HEXOBSERVER_H
#define CXXLEARNING_HEXOBSERVER_H

#include "iostream"
#include "Observer.h"
#include "../MySubject.h"

class HexObserver : public Observer {
public:
    HexObserver(MySubject *subject) : Observer(subject) {}

    void update() override {
        std::cout << "BinaryObserver update: " << std::hex << (((MySubject *) subject)->getState()) << std::endl;
    }
};

#endif //CXXLEARNING_HEXOBSERVER_H
