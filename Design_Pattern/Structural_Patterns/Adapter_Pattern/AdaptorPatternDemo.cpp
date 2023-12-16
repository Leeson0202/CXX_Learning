//
// Created by ￼ Leeson on 2023/12/16.
//


#include "iostream"
#include "player/MediaPlayer.h"
#include "player/AudioPlayer.h"

int main() {
    MediaPlayer *player = new AudioPlayer();
    player->play("mp3", "file");
    player->play("mp4", "file");
    player->play("vlc", "file");


    return 1;
}