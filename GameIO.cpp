// This class handles I/O for the game, and calls methods in Game_manager.
// The purpose of this class is to easily switch between taing input from stdin
// and taking input from a save file.
//
// Author - Issa Chanzi <s3783615@student.rmit.edu.au>#include "GameIO.h"

#include "GameIO.h"

#include <iostream>
#include <cctype>

#define IN (*in)
#define OUT (*out)

#define PROMPT "> "

using std::string;

class NullBuf : public std::streambuf
{
public:
    int overflow(int ch)
    {
        return ch;
    }
    std::streamsize sputn( const char_type* s, std::streamsize count )
    {
       return count;
    }
    static NullBuf instance;
};

NullBuf NullBuf::instance;
std::ostream * GameIO::devNull = new std::ostream (&NullBuf::instance);

bool GameIO::moreInput ()
{
    while (std::isspace (IN.peek ()))
    {
        IN.get ();
    }

    return !IN.eof ();
}

GameIO::GameIO (
    Game_manager * game,
    std::istream * in,
    std::ostream * out)
{
    this->game = game;
    this->in = in;
    this->out = out;

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
        doTurn ();
    }
}

void GameIO::doTurn ()
{
    printTurn ();
    Turn * turn = getTurn ();
    int points = game->turn (turn);

    // TODO - NEED TO REMOVE OR PLACE SOMEWHERE ELSE
    OUT << "PLAYER POINTS: " << points << std::endl;
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

    OUT << PROMPT;
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
        else
        {
            turn = new Turn (factory, row, colour);
        }
    }
    else
    {
        OUT << "Invalid command. Correct format is "
            << "'turn <factory> <colour> <row>'." << std::endl;
    }

    return turn;
}

void GameIO::addPlayer ()
{
    std::string name;
    int playerNum = game->numPlayers () + 1;

    OUT << "Enter a name for player " << playerNum << std::endl << PROMPT;
    IN >> name;
    OUT << std::endl;

    game->add_player(new Player(name));
}

void GameIO::addPlayer (int numPlayers)
{
    for (int i = 0; i < numPlayers; i++)
    {
        addPlayer ();
    }
}

Game_manager * GameIO::loadGame ()
{
    int numPlayers = 2;

    delete this->game;

    // Load starting tile bag
    std::string startingTileBag;
    IN >> startingTileBag;

    this->game = new Game_manager (startingTileBag);

    // Load players
    addPlayer (numPlayers);

    // Load turns
    while (moreInput ())
    {
        doTurn();
    }

    return this->game;
}
