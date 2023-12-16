//
// Created by ￼ Leeson on 2023/12/12.
//

#include "string"
#include "iostream"


#ifndef C__LEARNING_SINGLEOBJECT_H
#define C__LEARNING_SINGLEOBJECT_H


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




#endif //C__LEARNING_SINGLEOBJECT_H
