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
    std::streamsize sputn(const char_type *s, std::streamsize count)
    {
        return count;
    }
    static NullBuf instance;
};

NullBuf NullBuf::instance;
std::ostream *GameIO::devNull = new std::ostream(&NullBuf::instance);

bool GameIO::moreInput()
{
    while (std::isspace(IN.peek()))
    {
        IN.get();
    }

    return !IN.eof();
}

GameIO::GameIO(
    Game_manager *game,
    std::istream *in,
    std::ostream *out)
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
void GameIO::doRound()
{
    OUT << std::endl
        << "=== Start Round === " << std::endl;
    while (!game->factoriesEmpty())
    {
        doTurn();
    }
    print_final(); //Prints the final scores / end of game
}

std::string GameIO::doCmd()
{
    OUT << PROMPT;

    std::string cmd;
    IN >> cmd;

    if (cmd == "turn")
    {
        cmd = turnCmd();
    }
    else if (cmd == "save")
    {
        saveCmd();
    }
    else if (IN.eof())
    {
        OUT << "Have a really awesome day. Goodbye." << std::endl;
        // TODO are we allowed to use exit()?
        exit(0);
    }

    return cmd;
}

std::string GameIO::turnCmd()
{
    std::string returnValue = "";

    Turn *turn = getTurn();
    if (turn != nullptr)
    {
        game->turn(turn);
        returnValue = "turn";
    }

    return returnValue;
}

void GameIO::saveCmd()
{
    std::string filename;
    IN >> filename;
    saveGame(filename);
}

void GameIO::doTurn()
{
    printTurn();
    while (doCmd() != "turn")
    {
    }
}

void GameIO::printTurn()
{
    Player *player = game->get_next_player();
    string playerName = player->get_name();

    OUT << "Turn for player: " << playerName << std::endl;

    //Print factories
    OUT << "Factories: " << std::endl;
    game->print_factories(OUT);

    //Print mozaic [sic]
    Mozaic *mozaic = player->get_mozaic();
    OUT << "Mozaic for: " << playerName << std::endl;
    OUT << *mozaic << std::endl;
}

Turn *GameIO::getTurn()
{
    Turn *turn = nullptr;

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

    //RECENTLY ADDED: THREE IF STATEMENTS AFTER MERGE
    // Checking if the mozaic tile has already been filled in that row
    if (game->get_next_player()->get_mozaic()->check_line(colour, row))
    {
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
        turn = new Turn(factory, row, colour);
    }

    return turn;
}

void GameIO::addPlayer()
{
    std::string name;
    int playerNum = game->numPlayers() + 1;

    OUT << "Enter a name for player " << playerNum << std::endl
        << PROMPT;
    IN >> name;
    OUT << std::endl;

    game->add_player(new Player(name));
}

void GameIO::addPlayer(int numPlayers)
{
    for (int i = 0; i < numPlayers; i++)
    {
        addPlayer();
    }
}

Game_manager *GameIO::loadGame()
{
    int numPlayers = 2;

    delete this->game;

    // Load starting tile bag
    std::string startingTileBag;
    IN >> startingTileBag;

    this->game = new Game_manager(startingTileBag);

    // Load players
    addPlayer(numPlayers);

    // Load turns
    while (moreInput())
    {
        doTurn();
    }

    return this->game;
}

void GameIO::saveGame(std::string filename)
{
    std::ofstream file(filename);
    file << *game;
}

void GameIO::print_final()
{ //RECENTLY ADDED - PROBLEM: SOMETIMES PRINTS PLAYER 2 FIRST INSTEAD OF PLAYER 1, DUE TO ROTATION
    OUT << "=== GAME OVER ===\n\n";
    OUT << "Final Scores: \n";
    OUT << "Player " << game->get_next_player()->get_name() << ": " << game->get_next_player()->get_points() << std::endl;
    game->cycle_players();
    OUT << "Player " << game->get_next_player()->get_name() << ": " << game->get_next_player()->get_points() << std::endl;
    game->cycle_players(); //need to remove, this is just for testing
    OUT << game->return_winner_name();
}
