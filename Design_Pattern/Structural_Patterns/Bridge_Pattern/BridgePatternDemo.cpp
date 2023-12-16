//
// Created by ￼ Leeson on 2023/12/16.
//
#include "./shape/Shape.h"
#include "./shape/Circle.h"
#include "./serviceApi/drawApi/Draw.h"
#include "./serviceApi/drawApi/BuleDraw.h"
#include "./serviceApi/drawApi/RedDraw.h"

int main() {
    Draw *draw = new BlueDraw();

    Shape *shape = new Circle(draw);
    shape->drawShape(1, 2, 3);


    draw = new RedDraw();

    shape = new Circle(draw);
    shape->drawShape(1, 2, 3);


    return 1;
}