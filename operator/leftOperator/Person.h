//
// Created by ￼ Leeson on 2023/9/30.
//

#ifndef C__LEARNING_PERSON_H
#define C__LEARNING_PERSON_H

#include <iostream>
#include <string>

class Person {
    friend std::ostream &operator<<(std::ostream &out, Person &person);

public:
    Person();

    Person(std::string name, int age);

private:
    std::string name;
    int age;

};


#endif //C__LEARNING_PERSON_H
