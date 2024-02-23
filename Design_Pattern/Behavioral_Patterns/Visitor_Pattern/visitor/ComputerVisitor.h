//
// Created by ￼ Leeson on 2023/12/21.
//

#ifndef CXXLEARNING_COMPUTERVISITOR_H
#define CXXLEARNING_COMPUTERVISITOR_H

#include "iostream"
#include "Visitor_Pattern/computer/ComputerPart.h"

class ComputerVisitor {
public:
    void visit(ComputerPart *computerPart) {
        std::cout << "visiting " << computerPart->getName() << std::endl;
    }
};

#endif //CXXLEARNING_COMPUTERVISITOR_H
