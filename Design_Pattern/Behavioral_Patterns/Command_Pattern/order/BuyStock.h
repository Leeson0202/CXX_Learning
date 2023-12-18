//
// Created by ￼ Leeson on 2023/12/18.
//

#ifndef CXXLEARNING_BUYSTOCK_H
#define CXXLEARNING_BUYSTOCK_H

#include "iostream"
#include "Order.h"
#include "../Stock.h"

class BuyStock : public Order {
public:
    explicit BuyStock(Stock *stock) : abStock(stock) {}

    void execute() override {
        abStock->buy();
    }

private:
    Stock *abStock;


};

#endif //CXXLEARNING_BUYSTOCK_H
