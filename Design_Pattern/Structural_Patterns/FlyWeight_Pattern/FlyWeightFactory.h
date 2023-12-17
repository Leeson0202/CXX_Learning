//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_FLYWEIGHTFACTORY_H
#define CXXLEARNING_FLYWEIGHTFACTORY_H

#include "iostream"
#include "map"
#include "shape/Shape.h"
#include "shape/Circle.h"

class FlyWeightFactory {
public:
    static Shape *getCircle(Color color) {
        auto item = m_map.find(color);
        if (item != m_map.end()) {
            return item->second;
        }
        auto shape = new Circle(color);
        m_map.insert({color, shape});
        return shape;
    }

private:
    static std::map<Color, Shape *> m_map;

};

#endif //CXXLEARNING_FLYWEIGHTFACTORY_H
