//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef CXXLEARNING_SQUARE_H
#define CXXLEARNING_SQUARE_H

#include "../Shape.h"
#include "iostream"

class Square : public Shape {
public:
    Square() {
        m_type = "Square";
    }

    Square(Square &square) {
        m_id = square.m_id;
        m_type = square.m_type;
    }

    Shape *Clone() override {
        return new Square(*this);
    }


};


#endif //CXXLEARNING_SQUARE_H
