//
// Created by ￼ Leeson on 2023/12/21.
//

#ifndef CXXLEARNING_COMPUTER_H
#define CXXLEARNING_COMPUTER_H

#include "ComputerPart.h"
#include "../visitor/ComputerVisitor.h"

class Computer : public ComputerPart {
public:
    Computer() {
        name = "computer";
    }

    void accept(void *visitor) override {
        (static_cast<ComputerVisitor *>(visitor))->visit(this);
    }
};

#endif //CXXLEARNING_COMPUTER_H
