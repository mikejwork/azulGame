#include "GameManager.h"

GameManager::GameManager() {
    std::cout << "Starting a New Game \n \n";
    setupPlayers();
    std::cout << "Let's play! \n \n";
    setupFactories();
    player_turn = player1_name;
    round_in_progress = true;
    
    for (int i = 0; i < 5; i++) { // Iterate over 5 rounds
        std::cout << "=== Start Round === \n";
        std::cout << "TURN FOR PLAYER: " << player_turn << "\n";
        std::cout << "Factories: \n"; 
        printFactories();

        // MOZAIC SHIT HERE
        bool done = false;
        while (!done) {
            done = inputCommand();
        }
    }
}

GameManager::~GameManager() {
    // TODO
}

bool GameManager::inputCommand() {
    std::cout << "> ";
    std::istream& inputStream = std::cin;
    std::string cmd;
    double selected_factory; // number of the selected factory
    char selected_colour; // char of the selected colour
    double selected_row;
    inputStream >> cmd;
    if (cmd == "turn") {
        inputStream >> selected_factory >> selected_colour >> selected_row;
        if (turn(selected_factory, selected_colour, selected_row)) {
            std::cout << "Turn successful." << std::endl;
            return true;
        } else {
            std::cout << "Turn invalid." << std::endl;
            return false;
        }
    } else if (cmd == "save") {
        return true;
    } else if (cmd == "exit") {
        exit(0);
    } else {
        std::cout << "Invalid" << std::endl;
        return false;
    }
    return false;
}

bool GameManager::turn(double factory, char colour, double row) {
    // 1. Select the factory and get number of the chosen colour in factory
    //       -- Should error check for invalid selection and return false
    return false;
}

void GameManager::setupFactories() {
    TileBag* bag = new TileBag(); // New tilebag (linkedlist) object

    std::string tiles = "YBBRRRLBULULRYBLBBLYRRUYUYUYUBBRLUBLRYLBLBUBUBRYRLLLRRUBYYBYYLRLRRYBURRLUYYYBUBLRUUBYLLBYYUULURYRUUL"; // Tiles, 20 of each colour, 100 total
    for (std::string::size_type i = 0; i < tiles.size(); i++) {
        Tile* newTile = new Tile(tiles[i]);
        bag->addBack(newTile);
    } // adds each tile as an object to the linked list

    // Prints out the tiles and their index
    // for (int i = 0; i != bag->size() + 1; i++) {
    //     std::cout << "tile[" << i << "] = " << bag->get(i)->getIdentifier() << std::endl;
    // }

    centre = new Factory(0);
    centre->addBack(new Tile('F'));

    one = new Factory(1);
    for (int i = 0; i < 4; i++) {
        one->addBack(bag->get(0));
        bag->removeFront();
    } 

    two = new Factory(2);
    for (int i = 0; i < 4; i++) {
        two->addBack(bag->get(0));
        bag->removeFront();
    }

    three = new Factory(3);
    for (int i = 0; i < 4; i++) {
        three->addBack(bag->get(0));
        bag->removeFront();
    } 

    four = new Factory(4);
    for (int i = 0; i < 4; i++) {
        four->addBack(bag->get(0));
        bag->removeFront();
    } 

    five = new Factory(5);
    for (int i = 0; i < 4; i++) {
        five->addBack(bag->get(0));
        bag->removeFront();
    } 
}

void GameManager::printFactories() {
    centre->toString();
    one->toString();
    two->toString();
    three->toString();
    four->toString();
    five->toString();
    std::cout << "\n";
}

void GameManager::setupPlayers() {
    std::cout << "Enter a name for player 1 \n> ";
    std::cin >> player1_name;
    std::cout << "\n";

    std::cout << "Enter a name for player 2 \n> ";
    std::cin >> player2_name;
    std::cout << "\n";
}

void GameManager::test() {
    // Temporary dont delete
}