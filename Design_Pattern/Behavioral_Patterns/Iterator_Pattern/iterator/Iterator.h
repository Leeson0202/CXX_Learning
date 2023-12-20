//
// Created by ￼ Leeson on 2023/12/19.
//

#ifndef CXXLEARNING_ITERATOR_H
#define CXXLEARNING_ITERATOR_H

#include "iostream"

class Iterator {
public:
    virtual bool hasNext() = 0;

    virtual void next() = 0;

    virtual std::string get() = 0;
};

#endif //CXXLEARNING_ITERATOR_H
