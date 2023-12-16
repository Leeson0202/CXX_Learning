//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef C__LEARNING_AUDIOPLAYER_H
#define C__LEARNING_AUDIOPLAYER_H

#include "MediaPlayer.h"
#include "adapter/AdvancedMediaPlayerAdapter.h"

class AudioPlayer : public MediaPlayer {

public:
    void play(std::string audioType, std::string fileName) override;

private:
    AdvancedMediaPlayerAdapter *adapter;

};


#endif //C__LEARNING_AUDIOPLAYER_H
