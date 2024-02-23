//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"
#include "computer/Computer.h"
#include "computer/Keyboard.h"
#include "computer/Mouse.h"

#include "visitor/ComputerVisitor.h"

using namespace std;


int main() {
    auto visitor = new ComputerVisitor();
    auto computer = new Computer();
    auto keyboard = new Keyboard();
    auto mouse = new Mouse();

    computer->accept(visitor);
    keyboard->accept(visitor);
    mouse->accept(visitor);


    return 0;
}