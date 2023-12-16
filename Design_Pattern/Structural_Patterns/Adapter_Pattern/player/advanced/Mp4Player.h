//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef C__LEARNING_MP4PLAYER_H
#define C__LEARNING_MP4PLAYER_H
#include "AdvancedMediaPlayer.h"

class Mp4Player: public AdvancedMediaPlayer{
public:
    // 啥都不做
    void playVlc(std::string filename) override{}
    void playMp4(std::string filename) override;


};


#endif //C__LEARNING_MP4PLAYER_H
