#include "GameManager.h"

GameManager::GameManager() {
    setupTileBag();
    setupFactories();
}

GameManager::~GameManager() {
    // TODO
    players.clear ();
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
    Player * player = getNextPlayer ();
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
    Mozaic * mozaic = player->getMozaic ();
    if (!mozaic->placeTiles(new Tile(colour), row, amount)) {
        turnSuccessful = false;
    } else {
        selected->removeFromFactory(colour, *centre); // Removes every tile from the factory with that certain colour.
        selected->clear();
    }

    cyclePlayers ();

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



void GameManager::addPlayer (Player * player)
{
   players.push_back (player);
}

Player * GameManager::getNextPlayer ()
{
    return players [playerTurn];
}

void GameManager::cyclePlayers ()
{
    playerTurn ++;
    if (playerTurn >= (int) players.size())
    {
        playerTurn = 0;
    }
}

void GameManager::test() {
    // Temporary dont delete
}
