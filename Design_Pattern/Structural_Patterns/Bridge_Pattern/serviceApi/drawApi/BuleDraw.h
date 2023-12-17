//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef CXXLEARNING_BLUEDRAW_H
#define CXXLEARNING_BLUEDRAW_H

#include "Draw.h"
#include "iostream"

class BlueDraw : public Draw {
public:
    void draw(int radius, int x, int y) override {
        std::cout << "drawing Blue:{" << std::endl
                  << "  x: " << x << std::endl
                  << "  y: " << y << std::endl
                  << "  radius: " << radius << std::endl
                  << "}" << std::endl;
    }

};


#endif //CXXLEARNING_BLUEDRAW_H
