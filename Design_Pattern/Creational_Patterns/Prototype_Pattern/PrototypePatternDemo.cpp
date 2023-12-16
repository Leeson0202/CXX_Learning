//
// Created by ￼ Leeson on 2023/12/12.
//
#include "iostream"
#include "string"
#include "prototype/PrototypeCache.h"
#include "prototype/Shape.h"

using namespace std;


int main() {
    PrototypeCache::loadCache();
    Shape *shape = PrototypeCache::getById("1");
    cout << shape->getId() + shape->getType() + " 地址：" << shape << endl;

    shape = PrototypeCache::getById("1");
    cout << shape->getId() + shape->getType() + " 地址：" << shape << endl;


    shape = PrototypeCache::getById("2");
    cout << shape->getId() + shape->getType() + " 地址：" << shape << endl;

    shape = PrototypeCache::getById("2");
    cout << shape->getId() + shape->getType() + " 地址：" << shape << endl;


    return 0;
}