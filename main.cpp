#include <iostream>
#include <limits>
#include "TileBag.h"
#include "Factory.h"
#include "GameManager.h"
#include "Player.h"
#include "GameIO.h"
#include "SaveManager.h"

#define NEW_GAME 1
#define LOAD_GAME 2
#define CREDITS 3
#define QUIT 4

#define NUM_PLAYERS 2
#define NUM_ROUNDS 5

// Function definitions
void tests();
void showCredits();
int showMenu();

void setupPlayers ();
void newGame ();

int main(void) {
    std::cout << "Welcome to Azul!" << std::endl << "--------------------\n" << std::endl;
    int state = showMenu();
    if (state == NEW_GAME) {
        newGame ();
    } else if (state == LOAD_GAME) {
        // TODO
    } else if (state == CREDITS) {
        showCredits();
    } else if (state == QUIT) {
        exit(1);
    }

    return EXIT_SUCCESS;
}

int showMenu() {
    std::cout << "Menu" << std::endl
              << "----" << std::endl
              << "1. New Game" << std::endl
              << "2. Load Game" << std::endl
              << "3. Credits" << std::endl
              << "4. Quit" << std::endl;
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
    return a;
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

void setupPlayers(GameManager * game, int numPlayers) {

    for (int i = 1; i <= numPlayers; i++)
    {
        std::string playerName;
        std::cout << "Enter a name for player " << i << std::endl << "> ";
        std::cin >> playerName;
        std::cout << std::endl;

        Player * player = new Player (playerName);
        game->addPlayer (player);
    }
}

void newGame ()
{
    std::cout << "Starting a New Game" << std::endl << std::endl;
    GameManager * game = new GameManager ();
    setupPlayers (game, NUM_PLAYERS);

    std::cout << "Let's play!" << std::endl << std::endl;
    SaveManager * saveManager = nullptr; // TODO Saving

    GameIO * io = new GameIO (game, saveManager);

    io->playGame (NUM_ROUNDS);

    delete io;
    delete saveManager;
    delete game;

}
