//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_REDSHAPEDECORATOR_H
#define CXXLEARNING_REDSHAPEDECORATOR_H

#include "iostream"
#include "ShapeDecorator.h"
#include "../shape/Shape.h"

class RedShapeDecorator : public ShapeDecorator {
public:
    explicit RedShapeDecorator(Shape *shape) : ShapeDecorator(shape) {}

    void draw() {
        setRedBorder();
        shape->draw();
    }

    void setRedBorder() {
        std::cout << "setRedBorder" << std::endl;
    }
};

#endif //CXXLEARNING_REDSHAPEDECORATOR_H
