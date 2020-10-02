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
        print_final(); //USED TO TEST OUT IF THE SCORING SYSTEM WORKS - IT DOES
        // TODO - NEED TO REMOVE OR PLACE SOMEWHERE ELSE
        OUT << "PLAYER POINTS: " << points << std::endl;
    }
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

        if (colour == 'F')
        {
            OUT << "you cannot move the 'F' tile! \n";
            turn = nullptr;
        }
        if(game->get_next_player()->get_mozaic()->check_line(colour, row)) { //can be replaced by checkColour();
            OUT << "Cannot place tile there! \n";
            turn=nullptr;
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
    OUT << "Player " << game->return_winner_name() << " wins! \n" <<std::endl;
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