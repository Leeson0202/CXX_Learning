//
// Created by ￼ Leeson on 2023/12/16.
//

#include "./Person.h"

string Person::get() {}

std::ostream &operator<<(std::ostream &out, Person *person) {
    std::cout << "Person:{" << endl
              << "    name: " << person->name << endl
              << "    gender: " << person->gender << endl
              << "    status: " << person->maritalStatus << endl
              << "}" << endl;
    return out;
}