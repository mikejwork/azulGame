#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Player.h"
#include "Factory.h"
#include "TileBag.h"
#include "Turn.h"

#include <vector>
#include <iostream>
#include <string>

class Game_manager
{
public:
    Game_manager();
    ~Game_manager();

    Player* get_next_player();
    void cycle_players();

    bool factoriesEmpty ();
    int turn(Turn * turn);
    void print_factories(std::ostream & stream);

private:
    // Player related-----------------
    int player_turn;
    Player* player_one;
    Player* player_two;
    std::vector<Player*> players;
    void setup_players();
    void add_player(Player* player);

    // Factory related-----------------
    void setup_factories();
    bool check_if_empty();
    std::vector<Factory*> factories;
    void leftovers_to_centre(char colour, int factory);

    // Tilebag related-----------------
    TileBag* tilebag;

    // Round related-------------------
    void process_rounds();
    bool process_turn();
    bool first_tile_taken;
};


#endif // GAME_MANAGER_H
