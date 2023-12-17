//
// Created by ￼ Leeson on 2023/12/12.
//

#include "string"
#include "iostream"


#ifndef CXXLEARNING_SINGLEOBJECT_H
#define CXXLEARNING_SINGLEOBJECT_H


class SingleObject {
public:
    static SingleObject &getInstance() {
        return singleObject;
    }

    void showMessage(std::string message);

protected:
    SingleObject() {}

    static SingleObject singleObject;


};




#endif //CXXLEARNING_SINGLEOBJECT_H
