//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef CXXLEARNING_BIKE_H
#define CXXLEARNING_BIKE_H

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


#endif //CXXLEARNING_BIKE_H
