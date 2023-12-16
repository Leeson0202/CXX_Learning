//
// Created by ￼ Leeson on 2023/12/3.
//

#include "ShapeFactory.h"
#include "string"
#include "../../shape/Square.h"
#include "../../shape/Cycle.h"

Shape *ShapeFactory::getShape(std::string shapeName) {
    if (shapeName == "CYCLE") {
        return new Cycle();
    } else if (shapeName == "SQUARE") {
        return new Square();
    }
    return nullptr;
}

Color *ShapeFactory::getColor(std::string colorName) {
    return nullptr;
}