//
// Created by ￼ Leeson on 2023/12/21.
//

#ifndef CXXLEARNING_GAME_H
#define CXXLEARNING_GAME_H


class Game {
private:
    virtual void initialize() = 0;

    virtual void startPlay() = 0;

    virtual void endPlay() = 0;

public:
    void play() {
        initialize();
        startPlay();
        endPlay();
    }
};

#endif //CXXLEARNING_GAME_H
