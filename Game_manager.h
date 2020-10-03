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
    Game_manager ();
    Game_manager (std::string startingTileBag);
    ~Game_manager ();

    void add_player(Player* player);
    Player* get_next_player();
    void cycle_players();
    int numPlayers ();

    bool factoriesEmpty ();
    int turn(Turn * turn);
    void print_factories(std::ostream & stream);

    friend std::ostream & operator<< (
        std::ostream & stream,
        Game_manager & game);

    //Braden Implementation - Remove this IF NEEDED
    std::string return_winner_name();
    // Braden also made factories public but I've left it private for now

private:
    // Player related-----------------
    int player_turn;
    std::vector<Player*> players;
    void setup_players();

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

    std::vector <Turn *> turns;
};


#endif // GAME_MANAGER_H
