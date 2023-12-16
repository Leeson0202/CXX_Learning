//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef C__LEARNING_SQUARE_H
#define C__LEARNING_SQUARE_H

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


#endif //C__LEARNING_SQUARE_H
