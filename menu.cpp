#include "menu.h"

#include "GameIO.h"

#define NEW_GAME 1
#define LOAD_GAME 2
#define CREDITS 3
#define QUIT 4

#define NUM_ROUNDS 5

Menu::Menu() {
    std::cout << "Welcome to Azul!" << std::endl << "--------------------\n" << std::endl;
}

// Display the main menu of the game
void Menu::display_menu()
{
    std::cout << "Menu" << std::endl
    << "----" << std::endl
    << "1. New Game \n"
    << "2. Load Game \n"
    << "3. Credits \n"
    << "4. Quit \n \n";
    // Take int input and validate it
    int input = 0;
    bool valid = true;

    // Error checking / validation of user input
    do {
        std::cout << "> ", std::cin >> input;
        if (std::cin.fail() || input > 4 || input < 1)
        {
            std::cin.clear();
            std::cin.ignore(9999999, '\n');
            std::cout << "Invalid input" << std::endl;
            valid = false;
        }

    } while (!valid);
    // Send validated input to be processed
    input_logic(input);
}

void Menu::input_logic(int input)
{
    if (input == NEW_GAME)
    {
        game_manager = new Game_manager();
        playGame ();
    }
    else if (input == LOAD_GAME)
    {
        if (loadGame ())
        {
            playGame ();
        }
    }
    else if (input == CREDITS)
    {
        // Dgame_managerisplay the credits
        display_credits();
    }
    else if (input == QUIT)
    {
        // Quit the program
        // + Memory cleanup
    }
}

bool Menu::loadGame ()
{
    bool success = true;

    std::cout << "Enter file name" << std::endl << "> ";

    std::string filename;
    std::cin >> filename;

    std::ifstream file (filename);
    GameIO * io = new GameIO (nullptr, &file, nullptr);
    game_manager = io->loadGame ();
    delete io;

    if (game_manager == nullptr)
    {
        std::cout << "ERROR - " << filename << " is not a valid save file."
            << std::endl;
        success = false;
    }

    return success;
}

void Menu::playGame ()
{
    GameIO * io = new GameIO (game_manager, &std::cin, &std::cout);

    // TODO Make game track total number of rounds.
    // TODO Currently, if a saved game is loaded, the game will play 5 *more*
    // TODO rounds, instead of until 5 total rounds.
    for (int i = 0; i < NUM_ROUNDS; i++)
    {
        // Initiate a round
        io->doRound ();
        std::cout << "\n=== END OF ROUND === \n"; // TODO: Issa change to gameio if needed
        // after round has completed, re-populate factories
        // Takes from front of tilebag (also in the scoring system)
        // the tiles will be moved to the back of the tilebag
        game_manager->populate_factories();
    }
    io->print_final();
}

void Menu::display_credits()
{
    std::cout << std::endl << "---------------------------------- \n"

    << "Name: Braden Smith \n"
    << "Student ID: s3787174 \n"
    << "Email: s3787174@student.rmit.edu.au \n \n"

    << "Name: Michael Jurie \n"
    << "Student ID: s3785631 \n"
    << "Email: s3785631@student.rmit.edu.au \n \n"

    << "Name: Issa Chanzi \n"
    << "Student ID: s3783615 \n"
    << "Email: s3783615@student.rmit.edu.au \n"

    << "---------------------------------- \n \n";

    // send the user back to the menu
    display_menu();
}
