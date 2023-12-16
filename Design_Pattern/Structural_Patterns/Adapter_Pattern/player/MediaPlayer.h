//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef C__LEARNING_MEDIAPLAYER_H
#define C__LEARNING_MEDIAPLAYER_H

#include "iostream"

class MediaPlayer {
public:
    virtual void play(std::string audioType, std::string fileName) = 0;

};


#endif //C__LEARNING_MEDIAPLAYER_H
