#include <iostream>
#include <limits>
#include "GameManager.h"
#include "SaveManager.h"

void exit();
void showCredits();
void showMenu();
void loadSave();
int getInput();

SaveManager* saveManager = new SaveManager();

int main(int argc, char** argv) {
    
    
    std::cout << "Welcome to Azul!" << 
    std::endl << "---------------------" << 
    std::endl;
    showMenu();

    delete saveManager;
    return EXIT_SUCCESS;
}

void exit() {
    // delete / cleanup memory
    exit(0); // Exits the program
}

void showMenu() {
    std::cout << std::endl << "Menu" << 
    std::endl << "----" << 
    std::endl << "1. New Game" <<
    std::endl << "2. Load Game" <<
    std::endl << "3. Credits" <<
    std::endl << "4. Quit \n" <<
    std::endl;
    bool selected = false;
    while (!selected) {
        int input = getInput();
        if (input == 1) {
            // TODO New Game
            selected = true;
            showMenu();
        } else if (input == 2) {
            loadSave();
            selected = true;
        } else if (input == 3) {
            showCredits();
            selected = true;
        } else if (input == 4) {
            exit();
            selected = true;
        }
    selected = false;

    }
    
}

void showCredits() {
    std::cout << std::endl << "----------------------------------" << std::endl;

    std::cout << "Name: Braden Smith" << std::endl;
    std::cout << "Student ID: s3787174" << std::endl;
    std::cout << "Email: s3787174@student.rmit.edu.au" << "\n"<< std::endl;

    std::cout << "Name: Victoria Elliot" << std::endl;
    std::cout << "Student ID: s3710716" << std::endl;
    std::cout << "Email: s3710716@student.rmit.edu.au" << "\n"<< std::endl;

    std::cout << "Name: Michael Jurie" << std::endl;
    std::cout << "Student ID: s3785631" << std::endl;
    std::cout << "Email: s3785631@student.rmit.edu.au" << std::endl;

    std::cout << "----------------------------------" << std::endl;
    showMenu();
}

int getInput() {
    int a = 0;
    std::cout << "> ", std::cin >> a;
    if (std::cin.fail() || a > 4 || a < 1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid input" << std::endl;
    } else {
        return a;
    }
    return 0;
    // We dont need that while loop, already have checks in showMenu()
}

void loadSave() {

}