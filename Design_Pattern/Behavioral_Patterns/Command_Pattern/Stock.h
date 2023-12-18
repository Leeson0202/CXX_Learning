//
// Created by ￼ Leeson on 2023/12/18.
//

#ifndef CXXLEARNING_STOCK_H
#define CXXLEARNING_STOCK_H

#include "iostream"

using namespace std;

class Stock {
public:
    Stock() = default;

    Stock(string name, int quantity) : name(name), quantity(quantity) {}

    void buy() {
        cout << "Stock [ Name: " << name << ", Quantity: " << quantity << "] bought" << endl;
    }

    void sell() {
        cout << "Stock [ Name: " << name << ", Quantity: " << quantity << "] sold" << endl;
    }

private:
    string name = "alibab";
    int quantity = 100;
};

#endif //CXXLEARNING_STOCK_H
