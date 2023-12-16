//
// Created by ￼ Leeson on 2023/9/30.
//

#include "Person.h"

Person::Person() {
    this->name = "null";
    this->age = 0;

}

Person::Person(std::string name, int age) {
    this->name = name;
    this->age = age;
}

std::ostream &operator<<(std::ostream &out, Person &person) {
    out << "person.name = " << person.name << ", person.age = " << person.age << std::endl;
}