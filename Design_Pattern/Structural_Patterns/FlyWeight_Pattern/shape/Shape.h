//
// Created by ￼ Leeson on 2023/12/3.
//

#ifndef CXXLEARNING_SHAPE_H
#define CXXLEARNING_SHAPE_H

#include "iostream"

enum Color {
    Red = 1,
    Green,
    Yellow
};

class Shape {
public:
    Shape() = default;

    explicit Shape(Color color) : color(color) {}

    virtual void draw(int x, int y) = 0;

    void setColor(Color color) {
        color = color;
    }

protected:
    Color color;

};


#endif //CXXLEARNING_SHAPE_H
