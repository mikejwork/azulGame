#ifndef GAME_IO_H
#define GAME_IO_H

#include <iostream>

#include "Game_manager.h"

class GameIO
{
    public:
        GameIO (
            Game_manager * game,
            std::istream & in,
            std::ostream & out);
        void doRound ();

    private:
        Game_manager * game;
        std::istream * in;
        std::ostream * out;

        void printTurn ();
        Turn * getTurn ();
        Turn * inputTurn ();

        static std::ostream * devNull;
};


#endif
