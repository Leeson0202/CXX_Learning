//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef C__LEARNING_PERSON_H
#define C__LEARNING_PERSON_H

#include "iostream"
#include "string"

using namespace std;

class Person {
    friend std::ostream &operator<<(std::ostream &out, Person *person);

public:
    Person(string name, string gender, string maritalStatus) : name(name), gender(gender),
                                                               maritalStatus(maritalStatus) {}


    string getName() { return name; }

    string getGender() { return gender; }

    string getMaritalStatus() { return maritalStatus; }
    string get();

private:
    string name;
    string gender;
    string maritalStatus;
};

#endif //C__LEARNING_PERSON_H
