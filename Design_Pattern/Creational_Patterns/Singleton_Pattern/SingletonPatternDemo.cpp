//
// Created by ￼ Leeson on 2023/12/12.
//
#include "iostream"
#include "string"
#include "SingleObject.h"

using namespace std;


int main() {
    auto single = SingleObject::getInstance();
    single.showMessage("hello");

    return 0;
}