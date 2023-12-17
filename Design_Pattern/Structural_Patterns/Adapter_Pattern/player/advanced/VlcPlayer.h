//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef CXXLEARNING_VLCPLAYER_H
#define CXXLEARNING_VLCPLAYER_H

#include "AdvancedMediaPlayer.h"

class VlcPlayer : public AdvancedMediaPlayer {
    void playVlc(std::string filename) override;

    // 啥都不做
    void playMp4(std::string filename) override {}

};


#endif //CXXLEARNING_VLCPLAYER_H
