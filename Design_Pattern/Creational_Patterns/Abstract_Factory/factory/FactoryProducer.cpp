//
// Created by ￼ Leeson on 2023/12/3.
//

#include "FactoryProducer.h"
#include "./impl/ShapeFactory.h"
#include "./impl/ColorFactory.h"

AbstractFactory *FactoryProducer::getFactory(std::string factory) {
    if (factory == "SHAPE") {
        return new ShapeFactory();
    } else if (factory == "COLOR") {
        return new ColorFactory();
    }
    return nullptr;

}