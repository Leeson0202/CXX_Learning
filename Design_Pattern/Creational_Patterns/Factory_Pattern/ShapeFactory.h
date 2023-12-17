//
// Created by ￼ Leeson on 2023/12/3.
//

#ifndef CXXLEARNING_SHAPEFACTORY_H
#define CXXLEARNING_SHAPEFACTORY_H
#include "string"
#include "./shape/Shape.h"

class ShapeFactory {
public:
    Shape* getShape(std::string shapeName);
};


#endif //CXXLEARNING_SHAPEFACTORY_H
