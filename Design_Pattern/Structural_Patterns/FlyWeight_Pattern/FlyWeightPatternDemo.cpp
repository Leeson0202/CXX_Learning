//
// Created by ￼ Leeson on 2023/12/17.
//

#include "FlyWeightFactory.h"
#include "shape/Shape.h"
#include "shape/Circle.h"

int main() {
    auto *shape = FlyWeightFactory::getCircle(Green);
    shape->draw(1, 3);
    shape = FlyWeightFactory::getCircle(Red);
    shape->draw(2, 3);
    shape = FlyWeightFactory::getCircle(Red);
    shape->draw(2, 2);

    return 0;
}