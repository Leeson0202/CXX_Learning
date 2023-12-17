//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef CXXLEARNING_DIRECTOR_H
#define CXXLEARNING_DIRECTOR_H

#include "./builder/Builder.h"

class Director {
public:
    Director(Builder *builder) : m_builder(builder) {
    }

    /* 这个函数也可以直接放在Builder里面 */
    Bike construct() {
        m_builder->buildFrame();
        m_builder->buildSeat();
        return m_builder->createBike();
    }

private:
    Builder *m_builder;
};

#endif //CXXLEARNING_DIRECTOR_H
