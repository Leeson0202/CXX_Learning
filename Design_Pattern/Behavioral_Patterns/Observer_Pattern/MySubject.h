//
// Created by ￼ Leeson on 2023/12/20.
//
#pragma once
#ifndef CXXLEARNING_MYSUBJECT_H
#define CXXLEARNING_MYSUBJECT_H

#include "iostream"
#include "vector"
#include "observer/Observer.h"

class MySubject {
public:
    explicit MySubject(int state) : m_state(state) {}

    int getState() const {
        return m_state;
    }

    void setState(int state) {
        m_state = state;
        notifyAllObservers();
    }

    void attach(Observer *observer) {
        observers.push_back(observer);
    }


    void notifyAllObservers() {
        for (auto &item: observers) {
            item->update();
        }
    }

private:
    int m_state;
    std::vector<Observer *> observers;
};

#endif //CXXLEARNING_MYSUBJECT_H
