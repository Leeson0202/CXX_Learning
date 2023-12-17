//
// Created by ￼ Leeson on 2023/12/16.
//

#ifndef CXXLEARNING_ADVANCEDMEDIAPLAYERADAPTER_H
#define CXXLEARNING_ADVANCEDMEDIAPLAYERADAPTER_H

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


#endif //CXXLEARNING_ADVANCEDMEDIAPLAYERADAPTER_H
