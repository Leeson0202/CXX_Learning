//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_EMPLOYEE_H
#define CXXLEARNING_EMPLOYEE_H


#include "iostream"
#include "list"

class Employee {
    friend std::ostream &operator<<(std::ostream &out, const Employee *employee);

public:
    Employee(std::string name, std::string dept, int salary) : name(name), dept(dept), salary(salary) {}

    void add(Employee *employee);

    void remove(Employee *employee);

    std::list<Employee *> getSubordinates();

private:
    std::string name;
    std::string dept;
    int salary;
    std::list<Employee *> subordinates;


};


#endif //CXXLEARNING_EMPLOYEE_H
