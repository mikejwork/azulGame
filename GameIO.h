#ifndef GAME_IO
#define GAME_IO

#include <iostream>

#include "GameManager.h"
#include "SaveManager.h"
#include "Player.h"

class GameIO
{
public:
    GameIO (GameManager * game, SaveManager * save);
    void playGame (int numRounds);

private:
    bool turn();

    GameManager * game;
    SaveManager * save;
};


#endif //GAME_IO
