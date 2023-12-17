//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_SHAPEMAKER_H
#define CXXLEARNING_SHAPEMAKER_H

#include "shape/Shape.h"
#include "shape/Square.h"
#include "shape/Circle.h"
#include "shape/Rectangle.h"

class ShapeMaker {
public:
    ShapeMaker() {
        circle = new Circle();
        square = new Square();
        rectangle = new Rectangle();
    }

    void drawCircle() {
        circle->draw();
    }

    void drawSquare() {
        square->draw();
    }

    void drawRectangle() {
        rectangle->draw();
    }

private:
    Shape *circle;
    Shape *square;
    Shape *rectangle;

};


#endif //CXXLEARNING_SHAPEMAKER_H
