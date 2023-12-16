//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef C__LEARNING_ADVANCEDMEDIAPLAYER_H
#define C__LEARNING_ADVANCEDMEDIAPLAYER_H

#include "iostream"

class AdvancedMediaPlayer {
public:
    virtual void playVlc(std::string filename) = 0;

    virtual void playMp4(std::string filename) = 0;

};


#endif //C__LEARNING_ADVANCEDMEDIAPLAYER_H
