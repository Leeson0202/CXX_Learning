//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef C__LEARNING_SHAPE_H
#define C__LEARNING_SHAPE_H

#include "string"

using namespace std;

class Shape {
public:
    void setId(string id) {
        m_id = id;
    }

    string getId() {
        return m_id;
    }

    string getType() {
        return m_type;
    }

    virtual Shape *Clone() = 0;

protected:
    string m_id;
    string m_type;
};


#endif //C__LEARNING_SHAPE_H
