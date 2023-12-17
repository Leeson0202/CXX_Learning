//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef CXXLEARNING_SHAPE_H
#define CXXLEARNING_SHAPE_H

#include "../serviceApi/drawApi/Draw.h"

class Shape {
public:
    explicit Shape(Draw *draw) : draw(draw) {
    }


    virtual void drawShape(int x, int y, int radius) = 0;

protected:

    Draw *draw;


};


#endif //CXXLEARNING_SHAPE_H
