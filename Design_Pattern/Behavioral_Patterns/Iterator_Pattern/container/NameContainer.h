//
// Created by ￼ Leeson on 2023/12/19.
//

#ifndef CXXLEARNING_NAMECONTAINER_H
#define CXXLEARNING_NAMECONTAINER_H


#include "iostream"
#include "vector"
#include "Container.h"
#include "../iterator/NameIterator.h"

class NameContainer : public Container {
private:
    std::vector<std::string> names = {"hello", "bb", "haudc"};
public:
    NameContainer() = default;

    std::string get(int idx) {
        if (idx < names.size())
            return names[idx];
        return "";
    }

    int size() {
        return names.size();
    }

    Iterator *getIterator() override {
        return (Iterator *) new NameIterator(this);
    }

};


#endif //CXXLEARNING_NAMECONTAINER_H
