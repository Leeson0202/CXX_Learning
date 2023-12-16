//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef C__LEARNING_ANDCRITERIA_H
#define C__LEARNING_ANDCRITERIA_H

#include "iostream"
#include "list"
#include "./Criteria.h"
#include "algorithm"

class AndCriteria : public Criteria {
public:
    AndCriteria(Criteria *c1, Criteria *c2) {
        criteria = c1;
        other = c2;
    }

    std::list<Person *> meetCriteria(std::list<Person *> persons) override {
        list<Person *> res{};
        list<Person *> res1 = criteria->meetCriteria(persons);
        list<Person *> res2 = other->meetCriteria(persons);
        res.resize(min(res1.size(), res2.size()));  // 不然空间会非常大，出问题
        // 求并集 or
        set_intersection(res1.begin(), res1.end(), res2.begin(), res2.end(), res.begin());
        return res;
    }

private:
    Criteria *criteria;
    Criteria *other;
};

#endif //C__LEARNING_ANDCRITERIA_H
