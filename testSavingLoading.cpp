#include <iostream>
#include <fstream>

#include "GameIO.h"
#include "Game_manager.h"

#define IN_FILENAME "test.in"
#define OUT_FILENAME "test.out"

int main ()
{

    std::ifstream in;
    std::ofstream out;

    std::ofstream null;

    in.open (IN_FILENAME);
    out.open (OUT_FILENAME);

    GameIO * io = new GameIO (nullptr, &in, nullptr);

    Game_manager * game = io->loadGame ();

    out << *game;

    delete io;
    delete game;

    return 0;
}
