//
// Created by ￼ Leeson on 2023/12/3.
//



#ifndef CXXLEARNING_SQUARE_H
#define CXXLEARNING_SQUARE_H

#include "Shape.h"
#include "iostream"


class Square : public Shape {
public:
    void draw() override {
        std::cout << "square drawing" << std::endl;
    }
};


#endif //CXXLEARNING_SQUARE_H
