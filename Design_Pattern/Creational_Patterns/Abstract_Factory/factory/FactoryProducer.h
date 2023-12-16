//
// Created by ￼ Leeson on 2023/12/3.
//
#include "AbstractFactory.h"
#include "iostream"
#include "string"

#ifndef C__LEARNING_FACTORYPRODUCER_H
#define C__LEARNING_FACTORYPRODUCER_H


class FactoryProducer {
public:
    AbstractFactory* getFactory(std::string factory);
};


#endif //C__LEARNING_FACTORYPRODUCER_H
