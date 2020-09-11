#include "GameManager.h"

Player::Player(std::string name) :
   name(name)
{
}

GameManager::GameManager() {
    setupTileBag();
    std::cout << "Starting a New Game \n \n";
    setupPlayers();
    std::cout << "Let's play! \n \n";
    
    setupFactories();
    for (int i = 0; i < 5; i++) { // 5 Rounds
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

    std::cout << "=== GAME OVER === \n";
    std::cout << "Final Scores: \n";
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

bool GameManager::getFactory(double factory, Factory &factoryObj) {
    bool isSuccess = false;
    if (factory == 0) { 
        factoryObj = *centre;
        isSuccess = true;
    } else if (factory == 1) { 
        factoryObj = *one;
        isSuccess = true;
    } else if (factory == 2) { 
        factoryObj = *two; 
        isSuccess = true;
    } else if (factory == 3) { 
        factoryObj = *three;
        isSuccess = true;
    } else if (factory == 4) { 
        factoryObj = *four;
        isSuccess = true;
    } else if (factory == 5) { 
        factoryObj = *five; 
        isSuccess = true;
    }
    return isSuccess;
}

bool GameManager::turn(double factory, char colour, double row) {
    int amount = 0;
    bool turnSuccessful = true;
    
    
    if (colour == 'F') {
        std::cout << "You cannot pick the 'first' tile" << std::endl;
        turnSuccessful = false;
    }

    Factory* selected = new Factory(99);
    if (!getFactory(factory, *selected)) { // get the selected factory
        std::cout << "Not a valid factory" << std::endl;
        turnSuccessful = false;
    }
    amount = selected->numOfColour(colour); // get the amount of the tile selected from the certain factory and store as int.
    
    // Check if the player is trying to place tiles in a filled row
    // or a row with tiles of a different colour.
    if (!playerTurn->mozaic->placeTiles(new Tile(colour), row, amount)) {
        turnSuccessful = false;
    } else {
        selected->removeFromFactory(colour, *centre); // Removes every tile from the factory with that certain colour.
        selected->clear();
    } 
    return turnSuccessful;
}

void GameManager::setupTileBag() {
    bag = new TileBag(); // New tilebag (linkedlist) object

    std::string tiles = "YBBRRRLBULULRYBLBBLYRRUYUYUYUBBRLUBLRYLBLBUBUBRYRLLLRRUBYYBYYLRLRRYBURRLUYYYBUBLRUUBYLLBYYUULURYRUUL"; // Tiles, 20 of each colour, 100 total
    for (std::string::size_type i = 0; i < tiles.size(); i++) {
        Tile* newTile = new Tile(tiles[i]);
        bag->addBack(newTile);
    }
}

void GameManager::setupFactories() {

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