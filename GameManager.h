#include "Factory.h"
#include "Tile.h"
#include "TileBag.h"
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <vector>

class GameManager {
public:
    GameManager();
    ~GameManager();

    void test();

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
    std::string player_turn;

    Factory* centre;
    Factory* one;
    Factory* two;
    Factory* three;
    Factory* four;
    Factory* five;

    // Turn command variables

    // Save command variables
        
};