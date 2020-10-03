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
        
        //TEMPORARY
        bool checkColour(char colour, int row);


        void print_final();

        static std::ostream * devNull;
};


#endif
