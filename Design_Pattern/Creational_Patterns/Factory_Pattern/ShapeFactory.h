//
// Created by ￼ Leeson on 2023/12/3.
//

#ifndef C__LEARNING_SHAPEFACTORY_H
#define C__LEARNING_SHAPEFACTORY_H
#include "string"
#include "./shape/Shape.h"

class ShapeFactory {
public:
    Shape* getShape(std::string shapeName);
};


#endif //C__LEARNING_SHAPEFACTORY_H
