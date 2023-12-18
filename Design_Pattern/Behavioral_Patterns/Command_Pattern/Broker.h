//
// Created by ￼ Leeson on 2023/12/18.
//

#ifndef CXXLEARNING_BROKER_H
#define CXXLEARNING_BROKER_H

#include "iostream"
#include "list"
#include "./order/Order.h"

class Broker {
public:
    void takeOrder(Order *order) {
        orders.push_back(order);
    }

    void placeOrder() {
        for (const auto &item: orders) {
            item->execute();
        }
    }

private:
    std::list<Order *> orders;

};

#endif //CXXLEARNING_BROKER_H
