#include "GameManager.h"

Player::Player(std::string name) :
   name(name)
{
}

GameManager::GameManager() {
    std::cout << "Starting a New Game \n \n";
    setupPlayers();
    std::cout << "Let's play! \n \n";
    setupFactories();
    
    for (int i = 0; i < 25; i++) { // Iterate over 5 rounds (25 for testing)
        std::cout << "=== Start Round === \n";
        std::cout << "TURN FOR PLAYER: " << playerTurn->name << "\n";
        std::cout << "Factories: \n"; 
        printFactories();
        std::cout << "Mosaic for " << playerTurn->name << std::endl;
        playerTurn->mozaic->printMozaic();
        
        // This will iterate while the command recieved is false (player tries to make invalid turn etc..)
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
    bool isSuccessful = false;
    std::cout << "> ";
    std::istream& inputStream = std::cin;

    std::string cmd; // command 
    double selected_factory; // number of the selected factory
    char selected_colour; // char of the selected colour
    double selected_row; // number of selected row

    inputStream >> cmd; // get the command string input
    if (cmd == "turn") { 
        inputStream >> selected_factory >> selected_colour >> selected_row; // get the 3 variables that come after a turn command
        if (turn(selected_factory, selected_colour, selected_row)) {
            std::cout << "Turn successful. \n" << std::endl;
            isSuccessful = true;
        } else {
            std::cout << "Turn invalid." << std::endl;
            isSuccessful = false;
        }
    } else if (cmd == "save") {// Save game, TODO
        isSuccessful = true;
    } else if (cmd == "exit") {
        exit(1);
    } else {
        std::cout << "Invalid command" << std::endl;
        isSuccessful = false;
    }
    return isSuccessful;
}

bool GameManager::turn(double factory, char colour, double row) {
    Factory* selected;
    if (factory == 0) { selected = centre;
    } else if (factory == 1) { selected = one;
    } else if (factory == 2) { selected = two; // this is ugly asf
    } else if (factory == 3) { selected = three;
    } else if (factory == 4) { selected = four;
    } else if (factory == 5) { selected = five;
    } else { return false; }

    int amount = 0;
    amount = selected->numOfColour(colour); // get the amount of the tile selected from the certain factory and store as int.

    if (colour == 'F') {
        std::cout << "You cannot pick the 'first' tile" << std::endl;
        return false;
    }

    if (!playerTurn->mozaic->placeTiles(new Tile(colour), row, amount)) { // Check if the player is trying to place tiles in a filled row
                                                                          // or a row with tiles of a different colour.
        return false;
    }
    selected->removeFromFactory(colour); // Removes every tile from the factory with that certain colour.
    return true;
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
    Player* one = new Player(player1_name);
    one->mozaic = new Mozaic();
    playerTurn = one;

    std::cout << "Enter a name for player 2 \n> ";
    std::cin >> player2_name;
    std::cout << "\n";
    Player* two = new Player(player2_name);
    two->mozaic = new Mozaic();
}

void GameManager::test() {
    // Temporary dont delete
}