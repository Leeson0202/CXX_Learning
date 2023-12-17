//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef CXXLEARNING_MEDIAPLAYER_H
#define CXXLEARNING_MEDIAPLAYER_H

#include "iostream"

class MediaPlayer {
public:
    virtual void play(std::string audioType, std::string fileName) = 0;

};


#endif //CXXLEARNING_MEDIAPLAYER_H
