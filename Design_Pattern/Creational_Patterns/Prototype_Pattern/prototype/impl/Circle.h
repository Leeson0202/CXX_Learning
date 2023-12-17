//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef CXXLEARNING_CIRCLE_H
#define CXXLEARNING_CIRCLE_H

#include "../Shape.h"
#include "iostream"

class Circle : public Shape {
public:
    Circle() {
        m_type = "Circle";
    }

    Circle(Circle &circle) {
        m_id = circle.m_id;
        m_type = circle.m_type;
    }

    Shape *Clone() override {
        return new Circle(*this);
    }


};


#endif //CXXLEARNING_CIRCLE_H
