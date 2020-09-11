#include "Factory.h"
#include "Tile.h"
#include "TileBag.h"
#include "Mozaic.h"
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <vector>

class Player {
public:
   Player(std::string name);

   std::string name;
   Mozaic* mozaic;
};

class GameManager {
public:
    GameManager();
    ~GameManager();

    void test();
    Factory* centre;

private:
    void setupFactories();
    void printFactories();
    void setupPlayers();
    bool inputCommand();
    bool turn(double factory, char colour, double row);

    int round_number;
    bool round_in_progress;
    std::string player1_name;
    std::string player2_name;
    Player* playerTurn;
    bool getFactory(double factory, Factory &factoryObj);

    TileBag* bag;
    void setupTileBag();

    Factory* one;
    Factory* two;
    Factory* three;
    Factory* four;
    Factory* five;

    // Turn command variables

    // Save command variables
        
};