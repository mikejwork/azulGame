#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Factory.h"
#include "Tile.h"
#include "TileBag.h"
#include "Mozaic.h"
#include "Player.h"

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
    Factory* centre;

    void addPlayer (Player * player);
    Player * getNextPlayer ();

    bool turn(double factory, char colour, double row);

    void printFactories();

private:
    void setupFactories();

    int round_number;
    bool round_in_progress;

    //TODO get rid of these
    std::string player1_name;
    std::string player2_name;

    std::vector<Player *> players;

    int playerTurn;
    void cyclePlayers ();

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


#endif
