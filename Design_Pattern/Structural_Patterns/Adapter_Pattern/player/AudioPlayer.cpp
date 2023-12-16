//
// Created by ￼ Leeson on 2023/12/16.
//

#include "AudioPlayer.h"

void AudioPlayer::play(std::string audioType, std::string fileName) {
    // 判断类型
    if (audioType == "mp3") {
        std::cout << "mp3 is playing" << std::endl;
    } else if (audioType == "mp4" || audioType == "vlc") {
        adapter = new AdvancedMediaPlayerAdapter(audioType);
        adapter->play(audioType, fileName);
    }
}