//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef CXXLEARNING_MOBIKEBUILDER_H
#define CXXLEARNING_MOBIKEBUILDER_H

#include "../Builder.h"

class MobikeBuilder : public Builder {
public:
    Bike createBike() override;

    void buildFrame() override;

    void buildSeat() override;

};


#endif //CXXLEARNING_MOBIKEBUILDER_H
