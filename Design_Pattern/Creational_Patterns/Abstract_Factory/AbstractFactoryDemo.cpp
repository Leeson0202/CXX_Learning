//
// Created by ￼ Leeson on 2023/12/3.
//
#include "iostream"
#include "./factory/FactoryProducer.h"

int main() {
    FactoryProducer factoryProducer;
    AbstractFactory *shapeFactory = factoryProducer.getFactory("SHAPE");
    Shape *shape = shapeFactory->getShape("SQUARE");
    shape->draw();


    AbstractFactory *colorFactory = factoryProducer.getFactory("COLOR");
    Color *color = colorFactory->getColor("RED");
    color->fill();
    return 0;
}