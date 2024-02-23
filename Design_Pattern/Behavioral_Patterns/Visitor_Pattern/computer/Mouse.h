//
// Created by ￼ Leeson on 2023/12/21.
//

#ifndef CXXLEARNING_MOUSE_H
#define CXXLEARNING_MOUSE_H


#include "ComputerPart.h"
#include "../visitor/ComputerVisitor.h"

class Mouse : public ComputerPart {
public:
    Mouse() {
        name = "mouse";
    }

    void accept(void *visitor) override {
        (static_cast<ComputerVisitor *>(visitor))->visit(this);
    }
};

#endif //CXXLEARNING_MOUSE_H
