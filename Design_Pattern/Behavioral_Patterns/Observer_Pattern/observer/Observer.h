//
// Created by ￼ Leeson on 2023/12/20.
//
#pragma once
#ifndef CXXLEARNING_OBSERVER_H
#define CXXLEARNING_OBSERVER_H

#include "iostream"

class Observer {
public:
    explicit Observer(void *subject) : subject(subject) {}

    virtual void update() = 0;

protected:
    void *subject;
};

#endif //CXXLEARNING_OBSERVER_H
