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
        GameIO * io = new GameIO (game_manager, &std::cin, &std::cout);
        for (int i = 0; i < NUM_ROUNDS; i++)
        {
            io->doRound ();
        }
    }
    else if (input == LOAD_GAME)
    {
        // Load a game from save file
    }
    else if (input == CREDITS)
    {
        // Display the credits
        display_credits();
    }
    else if (input == QUIT)
    {
        // Quit the program
        // + Memory cleanup
    }
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
