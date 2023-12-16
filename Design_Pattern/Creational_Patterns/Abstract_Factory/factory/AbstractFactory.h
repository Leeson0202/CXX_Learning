//
// Created by ￼ Leeson on 2023/12/3.
//
#include "iostream"
#include "../shape/Shape.h"
#include "../color/Color.h"


#ifndef C__LEARNING_ABSTRACTFACTORY_H
#define C__LEARNING_ABSTRACTFACTORY_H


class AbstractFactory {
public:
    virtual Shape* getShape(std::string shapeName) = 0;
    virtual Color* getColor(std::string colorName) = 0;

};


#endif //C__LEARNING_ABSTRACTFACTORY_H
