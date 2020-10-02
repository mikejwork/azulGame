#include <iostream>
#include <fstream>

#include "GameIO.h"
#include "Game_manager.h"

#define IN_FILENAME "test.in"
#define OUT_FILENAME "test.out"

int main ()
{

    // To load a game
    std::ifstream in (IN_FILENAME);
    GameIO * io = new GameIO (nullptr, &in, nullptr);
    Game_manager * game = io->loadGame ();

    // To save a game
    std::ofstream out (OUT_FILENAME);
    out << *game;

    delete io;
    delete game;

    return 0;
}
