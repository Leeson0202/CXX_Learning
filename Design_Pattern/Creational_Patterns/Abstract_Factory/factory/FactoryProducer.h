//
// Created by ￼ Leeson on 2023/12/3.
//
#include "AbstractFactory.h"
#include "iostream"
#include "string"

#ifndef CXXLEARNING_FACTORYPRODUCER_H
#define CXXLEARNING_FACTORYPRODUCER_H


class FactoryProducer {
public:
    AbstractFactory* getFactory(std::string factory);
};


#endif //CXXLEARNING_FACTORYPRODUCER_H
