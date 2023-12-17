//
// Created by ￼ Leeson on 2023/10/1.
//

#ifndef CXXLEARNING_PERSON_H
#define CXXLEARNING_PERSON_H


#include <iostream>
#include <string>

class Person {
    friend std::ostream &operator<<(std::ostream &out, const Person &p);

public:
    Person() = default;

    Person(std::string name, int age, int height);

    bool operator<(const Person &other) const;


private:
    std::string m_name;
    int m_age{};
    int m_height{};
};


#endif //CXXLEARNING_PERSON_H
