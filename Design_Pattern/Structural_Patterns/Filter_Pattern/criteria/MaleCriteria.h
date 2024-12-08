//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef CXXLEARNING_MALECRITERIA_H
#define CXXLEARNING_MALECRITERIA_H

#include "iostream"
#include "list"
#include "./Criteria.h"
#include "algorithm"

class MaleCriteria : public Criteria {
public:
    std::list<Person *> meetCriteria(std::list<Person *> persons) override {
        list<Person *> res;
        for (const auto &item: persons){
            if(item->getGender() =="Male"){
                res.push_back(item);
            }
        }
        return res;
    }
};

#endif //CXXLEARNING_MALECRITERIA_H
