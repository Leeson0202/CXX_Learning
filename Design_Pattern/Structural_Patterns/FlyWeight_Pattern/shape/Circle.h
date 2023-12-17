//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_CIRCLE_H
#define CXXLEARNING_CIRCLE_H

#include "iostream"
#include "Shape.h"

class Circle : public Shape {
public:
    Circle() = default;

    explicit Circle(Color color) : Shape(color) {}

    void draw(int x, int y) override {
        std::cout << "circle drawing{addr: " << this << ", color: " << color << ", x: " << x << ", y: " << y << "}"
                  << std::endl;
    }
};


#endif //CXXLEARNING_CIRCLE_H
