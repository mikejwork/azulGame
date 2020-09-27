#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "player.h"
#include "factory.h"
#include "tilebag.h"
#include <vector>
#include <iostream>

class Game_manager
{
public:
    Game_manager();
    ~Game_manager();

    Player* get_next_player();
    void cycle_players();

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
    void print_factories();
    bool check_if_empty();
    std::vector<Factory*> factories;
    void leftovers_to_centre(char colour, int factory);

    // Tilebag related-----------------
    TileBag* tilebag;

    // Round related-------------------
    void process_rounds();
    bool process_turn();
    bool turn(int factory, char colour, int row);
    bool first_tile_taken;
};


#endif // GAME_MANAGER_H