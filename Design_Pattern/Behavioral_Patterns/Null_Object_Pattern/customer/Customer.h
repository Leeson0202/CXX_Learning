//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_CUSTOMER_H
#define CXXLEARNING_CUSTOMER_H

#include "iostream"

class Customer {
public:
    Customer() = default;

    Customer(std::string name) : m_name(name) {}

    virtual bool isNull() = 0;

    virtual std::string getName() = 0;

protected:
    std::string m_name;

};

#endif //CXXLEARNING_CUSTOMER_H
