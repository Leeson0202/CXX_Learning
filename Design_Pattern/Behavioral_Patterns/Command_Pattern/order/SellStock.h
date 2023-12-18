//
// Created by ￼ Leeson on 2023/12/18.
//

#ifndef CXXLEARNING_SELLSTOCK_H
#define CXXLEARNING_SELLSTOCK_H

#include "iostream"
#include "Order.h"
#include "../Stock.h"

class SellStock : public Order {
public:
    explicit SellStock(Stock *stock) : abStock(stock) {}

    void execute() override {
        abStock->sell();
    }

private:
    Stock *abStock;


};

#endif //CXXLEARNING_SELLSTOCK_H
