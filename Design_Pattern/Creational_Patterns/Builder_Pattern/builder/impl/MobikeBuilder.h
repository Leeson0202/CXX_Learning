//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef C__LEARNING_MOBIKEBUILDER_H
#define C__LEARNING_MOBIKEBUILDER_H

#include "../Builder.h"

class MobikeBuilder : public Builder {
public:
    Bike createBike() override;

    void buildFrame() override;

    void buildSeat() override;

};


#endif //C__LEARNING_MOBIKEBUILDER_H
