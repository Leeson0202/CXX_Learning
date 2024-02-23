//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"
#include "game/Game.h"
#include "game/Football.h"
#include "game/Cricket.h"

using namespace std;


int main() {
    Game *game = new Football();
    game->play();
    game = new Cricket();
    game->play();


    return 0;
}