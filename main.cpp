#include <iostream>
#include <limits>
#include "TileBag.h"
#include "Factory.h"
#include "GameManager.h"

enum State {
    NEWGAME,
    LOADGAME,
    CREDITS,
    EXIT
};

// Function definitions
void tests();
void showCredits();
State showMenu();

int main(void) {
    std::cout << "Welcome to Azul!" << std::endl 
              << "--------------------\n" << std::endl;
    State state = showMenu();
    // This would be cleaner with a switch :(
    if (state == NEWGAME) {
        GameManager* game = new GameManager();
        game->test();
    } else if (state == LOADGAME) {
        // TODO
    } else if (state == CREDITS) {
        showCredits();
    } else if (state == EXIT) {
        exit(1);
        // we would also cleanup everything here
        // delete state, gameManager objects etc..
    }

    return EXIT_SUCCESS;
}

// New menu system using an enum 'State' this is the framework for the game menu / command system too.
State showMenu() {
    std::cout << "Menu" << std::endl 
              << "----" << std::endl
              << "1. New Game" << std::endl
              << "2. Load Game" << std::endl
              << "3. Credits" << std::endl
              << "4. Quit" << std::endl;
    // int a    - holds the 1-4 value for the menu
    // bool notValid    - Determines if the given input is valid, if not, repeats input.
    int a = 0;
    bool notValid = false;
    do {
        std::cout << "> ", std::cin >> a;

        if (std::cin.fail() || a > 4 || a < 1) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input" << std::endl;
            notValid = true;
        }
    } while (notValid);
    if (a == 1) { return NEWGAME; } 
    else if (a == 2) { return LOADGAME; } 
    else if (a == 3) { return CREDITS; } 
    else if (a == 4) { return EXIT; } 
    return EXIT;
}

void showCredits() {
    std::cout << std::endl << "----------------------------------" << std::endl;

    std::cout << "Name: Braden Smith" << std::endl;
    std::cout << "Student ID: s3787174" << std::endl;
    std::cout << "Email: s3787174@student.rmit.edu.au" << "\n"<< std::endl;

    std::cout << "Name: Michael Jurie" << std::endl;
    std::cout << "Student ID: s3785631" << std::endl;
    std::cout << "Email: s3785631@student.rmit.edu.au" << "\n"<< std::endl;

    std::cout << "Name: Issa Chanzi" << std::endl;
    std::cout << "Student ID: s3783615" << std::endl;
    std::cout << "Email: s3783615@student.rmit.edu.au" << std::endl;

    std::cout << "----------------------------------" << std::endl;
    showMenu();
}