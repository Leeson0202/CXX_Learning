//
// Created by ￼ Leeson on 2023/12/17.
//

#include "Employee.h"


void Employee::add(Employee *employee) {
    subordinates.push_back(employee);
}

void Employee::remove(Employee *employee) {
    auto it = find(subordinates.begin(), subordinates.end(), employee);
    if (it != subordinates.end())
        subordinates.erase(it);
}

std::list<Employee *> Employee::getSubordinates() {
    return subordinates;
}

std::ostream &operator<<(std::ostream &out, const Employee *employee) {
    out << "Employee:{ name:" << employee->name
        << ", dept: " << employee->dept
        << ", salary: " << employee->salary
        << " }" << std::endl;
    return out;
}
