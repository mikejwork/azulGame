#include <iostream>

void exit();
void showCredits();
void showMenu();
int getInput();

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

    int input = getInput();
    if (input == 1) {
        // TODO New Game
    } else if (input == 2) {
        // TODO Load Game
    } else if (input == 3) {
        showCredits();
    } else if (input == 4) {
        exit();
    } else {
        std::cout << "Please enter a a valid number" << std::endl;
        showMenu();
    }
    std::cout << std::endl << std::endl;
}

void showCredits() {
    std::cout << "----------------------------------" << std::endl;

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
    while(a != 1 || a != 2 || a != 3 || a != 4){
    std::cout << "> ";
    std::cin >> a;
    if(a == 1 || a == 2 || a ==3 || a == 4){
        return a;
    } else {
        showMenu();
    }
    }
    return a;
}