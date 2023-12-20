//
// Created by ￼ Leeson on 2023/12/19.
//

#ifndef CXXLEARNING_CONTAINER_H
#define CXXLEARNING_CONTAINER_H

#include "../iterator/Iterator.h"

class Container {
public:
    virtual Iterator *getIterator() = 0;

    virtual std::string get(int idx) = 0;

    virtual int size() = 0;

};

#endif //CXXLEARNING_CONTAINER_H
