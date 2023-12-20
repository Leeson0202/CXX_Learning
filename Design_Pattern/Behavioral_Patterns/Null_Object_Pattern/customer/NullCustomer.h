//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_NULLCUSTOMER_H
#define CXXLEARNING_NULLCUSTOMER_H

#include "Customer.h"

class NullCustomer : public Customer {
public:
    bool isNull() override {
        return true;
    }

    std::string getName() override {
        return "Not Available in Customer Database";
    }
};

#endif //CXXLEARNING_NULLCUSTOMER_H
