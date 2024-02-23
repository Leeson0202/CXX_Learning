//
// Created by ￼ Leeson on 2023/12/21.
//

#ifndef CXXLEARNING_KEYBOARD_H
#define CXXLEARNING_KEYBOARD_H

#include "ComputerPart.h"
#include "../visitor/ComputerVisitor.h"
class Keyboard : public ComputerPart {
public:
    Keyboard() {
        name = "keyboard";
    }

    void accept(void *visitor) override {
        (static_cast<ComputerVisitor *>(visitor))->visit(this);
    }
};

#endif //CXXLEARNING_KEYBOARD_H
