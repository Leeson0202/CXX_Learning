//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_RECTANGLE_H
#define CXXLEARNING_RECTANGLE_H

#include "Shape.h"
#include "iostream"

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "rectangle drawing" << std::endl;
    }

};


#endif //CXXLEARNING_RECTANGLE_H
