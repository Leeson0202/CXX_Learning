//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef C__LEARNING_REDDRAW_H
#define C__LEARNING_REDDRAW_H

#include "Draw.h"
#include "iostream"

class RedDraw : public Draw {
public:
    void draw(int radius, int x, int y) override {
        std::cout << "drawing Red:{" << std::endl
                  << "  x: " << x << std::endl
                  << "  y: " << y << std::endl
                  << "  radius: " << radius << std::endl
                  << "}" << std::endl;
    }

};


#endif //C__LEARNING_REDDRAW_H
