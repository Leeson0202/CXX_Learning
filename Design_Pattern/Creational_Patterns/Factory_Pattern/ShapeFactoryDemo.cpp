//
// Created by ￼ Leeson on 2023/12/3.
//
#include "iostream"
#include "string"
#include "./ShapeFactory.h"
#include "./shape/Square.h"

using namespace std;


int main() {
    ShapeFactory factory;
    Shape *cycle = factory.getShape("CYCLE");
    cycle->draw();
    cout << "hello" << endl;
    Shape *square = factory.getShape("SQUARE");
    square->draw();

    return 1;
}