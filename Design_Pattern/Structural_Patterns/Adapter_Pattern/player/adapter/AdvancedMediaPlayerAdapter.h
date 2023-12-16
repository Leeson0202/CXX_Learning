//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef C__LEARNING_ADVANCEDMEDIAPLAYERADAPTER_H
#define C__LEARNING_ADVANCEDMEDIAPLAYERADAPTER_H

#include "../advanced/AdvancedMediaPlayer.h"
#include "iostream"

class AdvancedMediaPlayerAdapter {
public:
    AdvancedMediaPlayerAdapter() = default;

    explicit AdvancedMediaPlayerAdapter(std::string audioType);

    void play(std::string audioType, std::string filename);

private:
    AdvancedMediaPlayer *advancedMediaPlayer;

};


#endif //C__LEARNING_ADVANCEDMEDIAPLAYERADAPTER_H
