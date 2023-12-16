//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef C__LEARNING_BIKE_H
#define C__LEARNING_BIKE_H

#include "string"

using namespace std;


class Bike {
public:
    void setFrame(string frame);

    string getFrame();

    void setSeat(string seat);

    string getSeat();

private:
    string m_frame;
    string m_seat;

};


#endif //C__LEARNING_BIKE_H
