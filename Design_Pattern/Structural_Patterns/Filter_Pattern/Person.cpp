//
// Created by ￼ Leeson on 2023/12/16.
//

#include "./Person.h"

string Person::get() { return name; }

std::ostream &operator<<(std::ostream &out, Person *person) {
    out << "Person:{ name: " << person->name      << ", gender: " << person->gender
        << ", status: " << person->maritalStatus << " }" << std::endl;
    return out;
}