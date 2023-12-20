//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_REALCUSTOMER_H
#define CXXLEARNING_REALCUSTOMER_H

#include "Customer.h"

class RealCustomer : public Customer {
public:

    RealCustomer(std::string name) : Customer(name) {}

    bool isNull() override {
        return false;
    }

    std::string getName() override {
        return m_name;
    }
};

#endif //CXXLEARNING_REALCUSTOMER_H
