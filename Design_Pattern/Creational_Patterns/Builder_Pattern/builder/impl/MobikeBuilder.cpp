//
// Created by ￼ Leeson on 2023/12/13.
//

#include "MobikeBuilder.h"


Bike MobikeBuilder::createBike() {
    return m_bike;
}

void MobikeBuilder::buildFrame() {
    m_bike.setFrame("碳纤维车架");
}

void MobikeBuilder::buildSeat() {
    m_bike.setSeat("真皮座椅");
}