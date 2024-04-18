//
// Created by yaros on 13.03.2024.
//

#ifndef LIFEGAME_GAME_H
#define LIFEGAME_GAME_H
#include "Engine.h"

class Game: protected Engine {
public:
    Game();
     ~Game();

    void Run();
    virtual void View() = 0;

    void Show();

};


#endif //LIFEGAME_GAME_H
