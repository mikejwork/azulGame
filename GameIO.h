// This class handles I/O for the game, and calls methods in Game_manager.
// The purpose of this class is to easily switch between taing input from stdin
// and taking input from a save file.
//
// Author - Issa Chanzi <s3783615@student.rmit.edu.au>

#ifndef GAME_IO_H
#define GAME_IO_H

#include <iostream>

#include "Game_manager.h"

class GameIO
{
    public:
        GameIO (
            Game_manager * game,
            std::istream * in,
            std::ostream * out);

        // TODO delete this method
        void doRound ();

        void doTurn ();

        void addPlayer ();
        void addPlayer (int numPlayers);
        Game_manager * loadGame ();

    private:
        Game_manager * game;
        std::istream * in;
        std::ostream * out;

        void printTurn ();
        Turn * getTurn ();
        Turn * inputTurn ();

        bool moreInput ();

        static std::ostream * devNull;
};


#endif
