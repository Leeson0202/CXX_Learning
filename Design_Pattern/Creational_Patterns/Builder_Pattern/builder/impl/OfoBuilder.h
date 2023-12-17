//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef CXXLEARNING_OFOBUILDER_H
#define CXXLEARNING_OFOBUILDER_H

#include "../Builder.h"

class OfoBuilder : public Builder {
public:
    Bike createBike() override;

    void buildFrame() override;

    void buildSeat() override;

};


#endif //CXXLEARNING_OFOBUILDER_H
