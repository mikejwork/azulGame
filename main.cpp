#include <iostream>
#include <limits>
#include "TileBag.h"
#include "Factory.h"
#include "GameManager.h"

// Function definitions
void tests();
void showCredits();
int showMenu();

int main(void) {
    std::cout << "Welcome to Azul!" << std::endl << "--------------------\n" << std::endl;
    int state = showMenu();
    if (state == 1) {
        GameManager* game = new GameManager();
        game->test();
    } else if (state == 2) {
        // TODO
    } else if (state == 3) {
        showCredits();
    } else if (state == 4) {
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