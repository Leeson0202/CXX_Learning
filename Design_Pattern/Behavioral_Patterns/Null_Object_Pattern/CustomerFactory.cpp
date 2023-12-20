//
// Created by ￼ Leeson on 2023/12/21.
//

#include "CustomerFactory.h"


Customer *CustomerFactory::getCustomer(std::string name) {
    for (auto &item: names) {
        if (name == item) {
            return new RealCustomer(name);
        }
    }
    return new NullCustomer();
}

std::string CustomerFactory::names[10]{
"Leeson",
"Chen",
"Mo"
};