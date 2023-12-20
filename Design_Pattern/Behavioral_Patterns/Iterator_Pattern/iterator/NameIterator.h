//
// Created by ￼ Leeson on 2023/12/19.
//

#ifndef CXXLEARNING_NAMEITERATOR_H
#define CXXLEARNING_NAMEITERATOR_H

#include "Iterator.h"
#include "../container/NameContainer.h"

class NameIterator : public Iterator {
public:

    explicit NameIterator(Container *pRepository) : nameRepository(pRepository) {}

    bool hasNext() override {
        return idx < nameRepository->size() - 1;
    }

    void next() override {
        idx++;
    }

    std::string get() override {
        return nameRepository->get(idx);
    }

private:
    Container *nameRepository;
    int idx = 0;

};

#endif //CXXLEARNING_NAMEITERATOR_H
