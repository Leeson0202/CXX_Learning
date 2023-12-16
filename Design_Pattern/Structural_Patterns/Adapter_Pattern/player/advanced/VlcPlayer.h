//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef C__LEARNING_VLCPLAYER_H
#define C__LEARNING_VLCPLAYER_H

#include "AdvancedMediaPlayer.h"

class VlcPlayer : public AdvancedMediaPlayer {
    void playVlc(std::string filename) override;

    // 啥都不做
    void playMp4(std::string filename) override {}

};


#endif //C__LEARNING_VLCPLAYER_H
