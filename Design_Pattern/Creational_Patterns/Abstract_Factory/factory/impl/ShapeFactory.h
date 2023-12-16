//
// Created by ￼ Leeson on 2023/12/3.
//

#include "iostream"
#include "../AbstractFactory.h"
#include "../../shape/Shape.h"
#include "../../color/Color.h"

#ifndef C__LEARNING_SHAPEFACTORY_H
#define C__LEARNING_SHAPEFACTORY_H


class ShapeFactory : public AbstractFactory {
public:
    Shape *getShape(std::string shapeName);

    Color *getColor(std::string colorName);

};


#endif //C__LEARNING_SHAPEFACTORY_H
