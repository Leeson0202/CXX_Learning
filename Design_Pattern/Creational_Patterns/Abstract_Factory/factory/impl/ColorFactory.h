//
// Created by ￼ Leeson on 2023/12/3.
//

#include "../AbstractFactory.h"
#include "../../shape/Shape.h"
#include "../../color/Color.h"

#ifndef CXXLEARNING_COLORFACTORY_H
#define CXXLEARNING_COLORFACTORY_H


class ColorFactory : public AbstractFactory {
public:
    Shape *getShape(std::string shapeName);

    Color *getColor(std::string colorName);
};


#endif //CXXLEARNING_COLORFACTORY_H
