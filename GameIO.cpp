// This class handles I/O for the game, and calls methods in Game_manager.
// The purpose of this class is to easily switch between taing input from stdin
// and taking input from a save file.
//
// Author - Issa Chanzi <s3783615@student.rmit.edu.au>#include "GameIO.h"

#include "GameIO.h"

#include <iostream>

#define IN *in
#define OUT *out

using std::string;

std::ostream * GameIO::devNull = new std::ostream (nullptr);

GameIO::GameIO (
    Game_manager * game,
    std::istream & in,
    std::ostream & out)
{
    this->game = game;
    this->in = &in;
    this->out = &out;

    if (this->out == nullptr)
    {
        this->out = devNull;
    }
}

// A round lasts until all factories are empty.
void GameIO::doRound ()
{
    OUT << std::endl <<"=== Start Round === " << std::endl;
    while (!game->factoriesEmpty ())
    {
        printTurn ();
        Turn * turn = getTurn ();
        int points = game->turn (turn);

        // TODO store turn
        delete turn;

        // TODO - NEED TO REMOVE OR PLACE SOMEWHERE ELSE
        OUT << "PLAYER POINTS: " << points << std::endl;
    }
    print_final();
}

void GameIO::printTurn ()
{
    Player * player = game->get_next_player ();
    string playerName = player->get_name ();

    OUT << "Turn for player: " << playerName << std::endl;

    //Print factories
    OUT << "Factories: " << std::endl;
    game->print_factories(OUT);

    //Print mozaic [sic]
    Mozaic * mozaic = player->get_mozaic ();
    OUT << "Mozaic for: " << playerName << std::endl;
    OUT << *mozaic << std::endl;

}

Turn * GameIO::getTurn ()
{
    Turn * turn = nullptr;

    while (turn == nullptr)
    {
        turn = inputTurn ();
    }

    return turn;
}

Turn * GameIO::inputTurn ()
{
    Turn * turn = nullptr;

    OUT << "> ";
    string cmd; // command

    IN >> cmd; // get the command string input
    if (cmd == "turn")
    {
        int factory;
        int row;
        char colour;

        IN >> factory;
        IN >> colour;
        IN >> row;
        /*      Error checking      */

        // Check if player is trying to take the 'first' tile
        if (colour == 'F')
        {
            OUT << "you cannot move the 'F' tile! \n";
            turn = nullptr;
        }

        // Checking if the mozaic tile has already been filled in that row
        if(game->get_next_player()->get_mozaic()->check_line(colour, row)) { 
            OUT << "Cannot place tile(s) there! \n";
            turn = nullptr;
        }

        // Checking if selected factory actually contains the tile the player is requesting
        if (game->factories[factory]->get_amount(colour) == 0)
        {
            OUT << "Factory does not contain that tile! \n";
            turn = nullptr;
        }
        
        // Checks if the selected row is already full
        if (game->get_next_player()->get_mozaic()->isRowFull(row))
        {
            OUT << "Selected row is already full \n";
            turn = nullptr;
        }

        else
        {
            turn = new Turn (factory, row, colour);
        }
    }

    return turn;
}


void GameIO::print_final() { //RECENTLY ADDED - PROBLEM: SOMETIMES PRINTS PLAYER 2 FIRST INSTEAD OF PLAYER 1, DUE TO ROTATION
    OUT << "=== GAME OVER ===\n\n";
    OUT << "Final Scores: \n";
    OUT << "Player " << game->get_next_player()->get_name() << ": "<< game->get_next_player()->get_points() <<std::endl;
    game->cycle_players();
    OUT << "Player " << game->get_next_player()->get_name() << ": " << game->get_next_player()->get_points() <<std::endl;
    game->cycle_players(); //need to remove, this is just for testing 
    OUT << game->return_winner_name();
}



// bool GameIO::checkColour(char colour, int row)
// {
//     bool result= false;
//     if(game->get_next_player()->get_mozaic()->check_line(colour, row))
//     {
//         result=true;
//     }
//     return result;

// }