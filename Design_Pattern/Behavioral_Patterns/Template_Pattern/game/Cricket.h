//
// Created by ￼ Leeson on 2023/12/21.
//

#ifndef CXXLEARNING_CRIKET_H
#define CXXLEARNING_CRIKET_H
#include "iostream"
#include "Game.h"

using namespace std;

class Cricket : public Game {
private:
    void initialize() override {
        cout << "cricket initialize" << endl;
    }
    void startPlay() override{
        cout << "cricket startPlay" << endl;

    }
    void endPlay() override{
        cout << "cricket endPlay" << endl;
    }
};
#endif //CXXLEARNING_CRIKET_H
