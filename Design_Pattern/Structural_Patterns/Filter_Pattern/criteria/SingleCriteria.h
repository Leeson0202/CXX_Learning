//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef CXXLEARNING_SINGLECRITERIA_H
#define CXXLEARNING_SINGLECRITERIA_H

#include "iostream"
#include "list"
#include "./Criteria.h"
#include "algorithm"

class SingleCriteria : public Criteria {
public:
    std::list<Person *> meetCriteria(std::list<Person *> persons) override {
        list<Person *> res;
        for (const auto &item: persons) {
            if(item->getMaritalStatus() =="Single"){
                res.push_back(item);
            }
        }
        return res;
    }
};

#endif //CXXLEARNING_SINGLECRITERIA_H
