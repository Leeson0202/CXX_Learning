//
// Created by ￼ Leeson on 2023/12/3.
//

#include "ColorFactory.h"
#include "../../color/Green.h"
#include "../../color/Red.h"

Shape *ColorFactory::getShape(std::string shapeName) {
    return nullptr;
}

Color *ColorFactory::getColor(std::string colorName) {
    if (colorName == "GREEN") {
        return new Green();
    } else if (colorName == "RED") {
        return new Red();
    }
    return nullptr;
}
