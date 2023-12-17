//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_SHAPEDECORATOR_H
#define CXXLEARNING_SHAPEDECORATOR_H

#include "../shape/Shape.h"

class ShapeDecorator {
public:
    explicit ShapeDecorator(Shape *shape) : shape(shape) {}

    virtual void draw() = 0;

protected:
    Shape *shape;
};

#endif //CXXLEARNING_SHAPEDECORATOR_H
