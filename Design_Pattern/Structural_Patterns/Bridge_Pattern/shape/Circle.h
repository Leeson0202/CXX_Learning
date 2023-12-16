//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef C__LEARNING_CIRCLE_H
#define C__LEARNING_CIRCLE_H

#include "iostream"
#include "Shape.h"


class Circle : public Shape {
public:
    explicit Circle(Draw *draw) : Shape(draw) {
    }

    void drawShape(int x, int y, int radius) override {
        std::cout << "Circle is drawing" << std::endl;
        draw->draw(radius, x, y);

    }
};

#endif //C__LEARNING_CIRCLE_H
