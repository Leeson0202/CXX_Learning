//
// Created by ￼ Leeson on 2023/12/16.
//
#include "iostream"

#include "decorator/ShapeDecorator.h"
#include "decorator/RedShapeDecorator.h"
#include "shape/Shape.h"
#include "shape/Circle.h"
#include "shape/Square.h"

int main() {
    Shape * shape  = new Circle();
    ShapeDecorator * decorator = new RedShapeDecorator(shape);
    decorator->draw();

    shape  = new Square();
    decorator = new RedShapeDecorator(shape);
    decorator->draw();

    return 0;


}