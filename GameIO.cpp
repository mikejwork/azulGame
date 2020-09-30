#include "GameIO.h"

#include <iostream>

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
    *out << std::endl <<"=== Start Round === " << std::endl;
    while (!game->factoriesEmpty ())
    {
        printTurn ();
        Turn * turn = getTurn ();
        int points = game->turn (turn);

        // TODO store turn
        delete turn;

        // TODO - NEED TO REMOVE OR PLACE SOMEWHERE ELSE
        std::cout << "PLAYER POINTS: " << points << std::endl;
    }
}

void GameIO::printTurn ()
{
    Player * player = game->get_next_player ();
    string playerName = player->get_name ();

    *out << "Turn for player: " << playerName << std::endl;

    //Print factories
    string factories = game->print_factories();
    *out << "Factories: " << std::endl;
    *out << factories;

    //Print mozaic [sic]
    string mozaic = player->get_mozaic ()->print_mozaic ();
    *out << "Mozaic for: " << playerName << std::endl;
    *out << mozaic;

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

    *out << "> ";
    string cmd; // command

    *in >> cmd; // get the command string input
    if (cmd == "turn")
    {
        int factory;
        int row;
        char colour;

        *in >> factory;
        *in >> colour;
        *in >> row;

        if (colour == 'F')
        {
            *out << "you cannot move the 'F' tile! \n";
            turn = nullptr;
        }
        else
        {
            turn = new Turn (factory, row, colour);
        }
    }

    return turn;
}
