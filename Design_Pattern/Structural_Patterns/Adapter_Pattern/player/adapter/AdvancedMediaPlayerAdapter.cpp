//
// Created by ￼ Leeson on 2023/12/16.
//

#include "AdvancedMediaPlayerAdapter.h"
#include "iostream"
#include "../advanced/Mp4Player.h"
#include "../advanced/VlcPlayer.h"

AdvancedMediaPlayerAdapter::AdvancedMediaPlayerAdapter(std::string audioType) {
    if (audioType == "mp4") {
        advancedMediaPlayer = new Mp4Player();
    } else if (audioType == "vlc") {
        advancedMediaPlayer = new VlcPlayer();
    } else {
        std::cout << "audioType is not supported" << std::endl;
    }

}

void AdvancedMediaPlayerAdapter::play(std::string audioType, std::string filename) {
    advancedMediaPlayer->playMp4(filename);
    advancedMediaPlayer->playVlc(filename);

}