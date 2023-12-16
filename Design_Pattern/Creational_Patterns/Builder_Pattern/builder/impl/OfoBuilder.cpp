//
// Created by ￼ Leeson on 2023/12/13.
//

#include "OfoBuilder.h"
#include "iostream"
#include "../../product/Bike.h"
#include "string"


Bike OfoBuilder::createBike() {
    return m_bike;
}

void OfoBuilder::buildFrame() {
    m_bike.setFrame("铝合金车架");
}

void OfoBuilder::buildSeat() {
    m_bike.setSeat("橡胶座椅");
}