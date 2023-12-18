//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"

#include "./order/Order.h"
#include "./order/BuyStock.h"
#include "./order/SellStock.h"
#include "./Broker.h"


int main() {
    auto stock = new Stock("Apple", 2);
    auto order1 = new BuyStock(stock);
    auto order2 = new SellStock(stock);

    auto broker = new Broker();
    broker->takeOrder(order1);
    broker->takeOrder(order2);

    broker->placeOrder();


    return 0;
}