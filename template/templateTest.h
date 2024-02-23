//
// Created by ￼ Leeson on 2024/1/31.
//

#ifndef CXXLEARNING_TEMPLATETEST_H
#define CXXLEARNING_TEMPLATETEST_H

#include "iostream"

int g_num = 0;
using namespace std;
enum class Type {
    GTPU,
    UDP
};

template<Type T>
class TemplateTest {
public:
    static TemplateTest<T> Inst() {
        cout << "GTPU" << endl;
        TemplateTest<T> handle;
        return handle;
    }

    void Add() {
        cout << "Add: "<<(int) T << endl;
    }

    TemplateTest<T>() {
        cout << "g_num: " << g_num << endl;
        g_num++;
    }
};


#endif //CXXLEARNING_TEMPLATETEST_H
