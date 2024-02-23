//
// Created by ￼ Leeson on 2023/12/21.
//

#ifndef CXXLEARNING_FOOTBALL_H
#define CXXLEARNING_FOOTBALL_H

#include "iostream"
#include "Game.h"

using namespace std;

class Football : public Game {
private:
    void initialize() override {
        cout << "football initialize" << endl;
    }
    void startPlay() override{
        cout << "football startPlay" << endl;

    }
    void endPlay() override{
        cout << "football endPlay" << endl;
    }
};

#endif //CXXLEARNING_FOOTBALL_H
