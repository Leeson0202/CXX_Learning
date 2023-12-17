//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef CXXLEARNING_ADVANCEDMEDIAPLAYER_H
#define CXXLEARNING_ADVANCEDMEDIAPLAYER_H

#include "iostream"

class AdvancedMediaPlayer {
public:
    virtual void playVlc(std::string filename) = 0;

    virtual void playMp4(std::string filename) = 0;

};


#endif //CXXLEARNING_ADVANCEDMEDIAPLAYER_H
