//
// Created by ￼ Leeson on 2023/10/1.
//

#include "Person.h"


Person::Person(std::string name, int age, int height) : m_name(name), m_age(age), m_height(height) {

}

bool Person::operator<(const Person &other) const {
    if (this->m_age == other.m_age) {
        return this->m_height < other.m_height;
    }
    return this->m_age < other.m_age;
}

std::ostream &operator<<(std::ostream &out, const Person &p) {
    out << "name: " << p.m_name << ", age: " << p.m_age << ", height: " << p.m_height;
    return out;
}