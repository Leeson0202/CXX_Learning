//
// Created by ￼ Leeson on 2023/12/21.
//

#ifndef CXXLEARNING_COMPUTERPART_H
#define CXXLEARNING_COMPUTERPART_H

class ComputerPart {
public:
    virtual void accept(void *visitor) = 0;

    std::string getName() {
        return name;
    }

protected:
    std::string name;
};

#endif //CXXLEARNING_COMPUTERPART_H
