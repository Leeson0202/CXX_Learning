//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef CXXLEARNING_BUILDER_H
#define CXXLEARNING_BUILDER_H

#include "../product/Bike.h"

class Builder {
protected:
    Bike m_bike;
public:
    virtual Bike createBike() = 0;

    virtual void buildFrame() = 0;

    virtual void buildSeat() = 0;

};


#endif //CXXLEARNING_BUILDER_H
