//
// Created by ￼ Leeson on 2023/12/17.
//
#include "iostream"
#include "Employee.h"

int main() {
    Employee CEO{"Leeson", "CEO", 1000000};
    Employee headSales{"Gui", "Head Sales", 500000};
    Employee headMarketing{"Mo", "Head Marketing", 500000};
    Employee sales1{"Chen", "Sales", 50000};
    Employee sales2{"Zhang", "Sales", 50000};
    Employee marketing1{"Wu", "Marketing", 10000};
    Employee marketing2{"zou", "Marketing", 10000};

    headSales.add(&sales1);
    headSales.add(&sales2);
    headMarketing.add(&marketing1);
    headMarketing.add(&marketing2);

    CEO.add(&headSales);
    CEO.add(&headMarketing);

    // 打印该组织的所有员工
    std::cout << &CEO;
    auto ls = CEO.getSubordinates();
    for (const auto &item: ls) {
        std::cout << item;
        auto es = item->getSubordinates();
        for (const auto &ee: es) {
            std::cout << ee;
        }
    }
    return 0;
}