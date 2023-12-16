//
// Created by ￼ Leeson on 2023/12/16.
//
#include "iostream"
#include "criteria/Criteria.h"
#include "criteria/AndCriteria.h"
#include "criteria/OrCriteria.h"
#include "criteria/MaleCriteria.h"
#include "criteria/SingleCriteria.h"


int main() {
    list<Person *> persons;
    persons.push_back(new Person{"小明", "Male", "Marital"});
    persons.push_back(new Person{"小红", "FeMale", "Marital"});
    persons.push_back(new Person{"小陈", "Male", "Single"});
    persons.push_back(new Person{"小李", "Male", "Marital"});

    Criteria *criteria1 = new MaleCriteria();
    Criteria *criteria2 = new SingleCriteria();
    Criteria *criteria = new AndCriteria(criteria1, criteria2);
    list<Person *> malesAndSingle = criteria->meetCriteria(persons);
    for (auto item: malesAndSingle) {
        std::cout << (item);
    }


}