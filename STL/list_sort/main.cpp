//
// Created by ￼ Leeson on 2023/10/1.
//
#include <iostream>
#include <string>
#include <list>
#include "Person.h"


void test_list_sort() {
    std::cout << "test_list_sort" << std::endl;
    std::list<Person> persons;
    // 初始化
    for (int i = 0; i < 10; ++i) {
        Person p("person" + std::to_string(i + 1), rand() % 100, rand() % 30 + 160);
        persons.push_back(p);
    }
    // 排序
    persons.sort();
    // 打印
    for (auto person: persons) {
        std::cout << person << std::endl;
    }

}

int main() {
    test_list_sort();
    return 0;
}