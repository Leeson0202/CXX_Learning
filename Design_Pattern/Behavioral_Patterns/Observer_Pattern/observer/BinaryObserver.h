//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_BINARYOBSERVER_H
#define CXXLEARNING_BINARYOBSERVER_H

#include "iostream"
#include "Observer.h"
#include "Observer_Pattern/MySubject.h"

class BinaryObserver : public Observer {
public:
    explicit BinaryObserver(MySubject *subject) : Observer(subject) {}

    void update() override {
        std::cout << "BinaryObserver update: " << std::bitset<10>(((MySubject *) subject)->getState()) << std::endl;
    }
};

#endif //CXXLEARNING_BINARYOBSERVER_H
