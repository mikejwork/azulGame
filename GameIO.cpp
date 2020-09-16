#include "GameIO.h"

GameIO::GameIO (GameManager * game, SaveManager * save)
{
    this->game = game;
    this->save = save;
}

void GameIO::playGame (int numRounds)
{
    for (int i = 0; i < numRounds; i++) {
        Player * player = game->getNextPlayer ();
        std::string name = player->getName();

        std::cout << "=== Start Round === \n";
        std::cout << "TURN FOR PLAYER: " << name << std::endl;
        std::cout << "Factories: " << std::endl;
        game->printFactories();
        std::cout << "Mosaic for " << name << std::endl;
        player->getMozaic ()->printMozaic();

        // TODO - make this clearer in code
        // Repeat until we get valid input
        while (!turn ());

    }

    std::cout << "=== GAME OVER === " << std::endl;
    std::cout << "Final Scores: " << std::endl;
    // TODO - calcuate scores
    std::cout << "TODO scoring <3" << std::endl;

}

bool GameIO::turn()
{
    bool isSuccessful = false;
    std::cout << "> ";
    std::istream & in = std::cin;

    std::string cmd; // command

    in >> cmd; // get the command string input
    if (cmd == "turn") {
        int factory; // number of the selected factory
        char colour; // char of the selected colour
        int row; // number of selected row

        // Get the three variables
        in >> factory;
        in >> colour;
        in >> row;

        // TODO - Utilise Turn class
        // TODO - Implement turn logic

        if (game->turn(factory, colour, row)) {
            std::cout << "Turn successful. \n" << std::endl;
            isSuccessful = true;
        } else {
            std::cout << "Turn invalid." << std::endl;
            isSuccessful = false;
        }
    } else if (cmd == "save") {// Save game, TODO
        isSuccessful = true;
        // Save game
    } else if (cmd == "exit") {
        exit(1);
    } else {
        std::cout << "Invalid command" << std::endl;
        isSuccessful = false;
    }
    return isSuccessful;
}
