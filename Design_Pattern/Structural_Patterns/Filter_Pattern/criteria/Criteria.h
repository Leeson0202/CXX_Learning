//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef CXXLEARNING_CRITERIA_H
#define CXXLEARNING_CRITERIA_H

#include "list"
#include "../Person.h"

class Criteria {
public:
    virtual std::list<Person *> meetCriteria(std::list<Person *> persons) = 0;
};

#endif //CXXLEARNING_CRITERIA_H
