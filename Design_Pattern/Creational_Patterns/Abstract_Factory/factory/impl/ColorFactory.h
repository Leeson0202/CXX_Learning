//
// Created by ￼ Leeson on 2023/12/3.
//

#include "../AbstractFactory.h"
#include "../../shape/Shape.h"
#include "../../color/Color.h"

#ifndef C__LEARNING_COLORFACTORY_H
#define C__LEARNING_COLORFACTORY_H


class ColorFactory : public AbstractFactory {
public:
    Shape *getShape(std::string shapeName);

    Color *getColor(std::string colorName);
};


#endif //C__LEARNING_COLORFACTORY_H
