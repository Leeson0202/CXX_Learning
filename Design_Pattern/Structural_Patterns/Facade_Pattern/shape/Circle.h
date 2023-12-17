//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_CIRCLE_H
#define CXXLEARNING_CIRCLE_H

#include "iostream"
#include "Shape.h"

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "circle drawing" << std::endl;
    }
};


#endif //CXXLEARNING_CIRCLE_H
