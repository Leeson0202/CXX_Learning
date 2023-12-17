//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef CXXLEARNING_ORCRITERIA_H
#define CXXLEARNING_ORCRITERIA_H

#include "iostream"
#include "list"
#include "./Criteria.h"
#include "algorithm"

class OrCriteria : public Criteria {
public:

    OrCriteria(Criteria *c1, Criteria *c2) {
        criteria = c1;
        other = c2;
    }

    std::list<Person *> meetCriteria(std::list<Person *> persons) override {
        list<Person *> res;
        list<Person *> res1 = criteria->meetCriteria(persons);
        list<Person *> res2 = other->meetCriteria(persons);
        // 求交集 and
        set_union(res1.begin(), res1.end(), res2.begin(), res2.end(), res.begin());
        return res;
    }

private:
    Criteria *criteria;
    Criteria *other;
};

#endif //CXXLEARNING_ORCRITERIA_H
