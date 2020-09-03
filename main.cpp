#include <iostream>

void exit();
void showMenu();

int main(int argc, char** argv) {
    std::cout << "Welcome to Azul!" << 
    std::endl << "---------------------" << 
    std::endl;
    showMenu();

    return EXIT_SUCCESS;
}

void exit() {
    // DELETE ALL OBJECTS
    // CLEANUP
}

void showMenu() {
    std::cout << std::endl << "Menu" << 
    std::endl << "----" << 
    std::endl << "1. New Game" <<
    std::endl << "2. Load Game" <<
    std::endl << "3. Credits" <<
    std::endl << "4. Quit" <<
    std::endl;
}