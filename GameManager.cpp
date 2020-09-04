#include "GameManager.h"

GameManager::GameManager() {
    std::cout << "Starting a New Game" << std::endl << std::endl;
    initPlayerNames();
    std::cout << std::endl << "Let's Play!" << std::endl;
    playerTurn = playerOne;
    newRound();
    setupFactories();
    printFactories();
    
    // CREATING FACTORY EXAMPLE
    // Factory* zero = new Factory(0);
    // Factory* one = new Factory(1);
    
    // Tile* f = new Tile('F');
    // Tile* r = new Tile('R');
    // Tile* y = new Tile('Y');
    // Tile* b = new Tile('B');

    // zero->addTile(f);
    // one->addTile(r);
    // one->addTile(y);
    // one->addTile(y);
    // one->addTile(b);
    // std::cout << "Factories: " << std::endl;
    // zero->toString();
    // one->toString();

}

// When a save file is loaded.
GameManager::GameManager(int saveFile) {
    // The initial order of the tile bag when the game was created. (Note that while your Azul implementation
    // will always use the same order when a new game is created, you must support using a different order
    // when loading from a saved-game file.)

    // Player Names

    // The order of turns taken by the players
    GameManager();
}

GameManager::~GameManager() {

}

void GameManager::initPlayerNames() {
    std::cout << "Enter a name for player 1" << std::endl;
    std::cout << "> ", std::cin >> playerOne;
    std::cout << std::endl << "Enter a name for player 2" << std::endl;
    std::cout << "> ", std::cin >> playerTwo;
}

void GameManager::newRound() {
    std::cout << "=== Start Round ===" << std::endl;
    std::cout << "TURN FOR PLAYER: " << playerTurn << std::endl;

}

void GameManager::printFactories() {
    std::cout << "Factories:" << std::endl;
    zero->toString();
    one->toString();
    two->toString();
    three->toString();
    four->toString();
    five->toString();
    std::cout << std::endl;
}

void GameManager::setupFactories() {
    // TODO: Make tile bag
    // Kinda confused on how it works but it isnt random, kinda like an array that is fixed, where u take tiles from front and put the back onto the end.
    Tile* first = new Tile('F');
    zero = new Factory(0);
    one = new Factory(1);
    two = new Factory(2);
    three = new Factory(3);
    four = new Factory(4);
    five = new Factory(5);
    zero->addTile(first);
}