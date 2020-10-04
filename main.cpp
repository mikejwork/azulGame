#include "menu.h"
#include "GameIO.h"
#include "Game_manager.h"

#include <string>
#include <iostream>
#include <fstream>

void usage();
void testingMode (std::string filename);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        // Normal mode - open menu
        Menu* menu = new Menu();
        menu->display_menu();
    }
    else if (argc == 3)
    {
        // Testing mode
        std::string flag ( argv[1]);
        std::string filename (argv [2]);

        if (flag == "-t")
        {
            testingMode (filename);
        }
        else
        {
            usage ();
        }
    }
    else
    {
        usage ();
    }

    return EXIT_SUCCESS;
}

void testingMode (std::string filename)
{
    std::ifstream file (filename);

    GameIO * io = new GameIO (nullptr, &file, nullptr);
    Game_manager * game = io->loadGame ();
    delete io;

    if (game == nullptr)
    {
        std::cout << "ERROR - " << filename << " is not a valid save file."
            << std::endl;
    }
    else
    {
        io = new GameIO (game, nullptr, &std::cout);
        io->printGameState ();
        delete io;
        delete game;
    }
}

void usage ()
{
    std::cout << "Usage:" << std::endl;
    std::cout << "\tazul" << std::endl;
    std::cout << "\tOR" << std::endl;
    std::cout << "\tazul -t < filename" << std::endl;
}
