//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_CUSTOMERFACTORY_H
#define CXXLEARNING_CUSTOMERFACTORY_H

#include "customer/Customer.h"
#include "customer/NullCustomer.h"
#include "customer/RealCustomer.h"


class CustomerFactory {
public:
    static std::string names[10];

    static Customer *getCustomer(std::string name);

};

#endif //CXXLEARNING_CUSTOMERFACTORY_H
