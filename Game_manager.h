#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Player.h"
#include "Factory.h"
#include "TileBag.h"
#include "Turn.h"
#include "Mozaic.h"

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
    std::vector <Player *> & get_players ();

    bool factoriesEmpty ();
    int turn(Turn * turn);
    void print_factories(std::ostream & stream);

    friend std::ostream & operator<< (
        std::ostream & stream,
        Game_manager & game);

    //Braden Implementation - Remove this IF NEEDED
    std::string return_winner_name();
    // Braden also made factories public but I've left it private for now
    //Need factories public to access it from gameIO
    std::vector<Factory*> factories;

    //Error checking
    bool validFactory (int factory);
    bool validRow (int row);

private:
    // Player related-----------------
    int player_turn;
    std::vector<Player*> players;
    void setup_players();
    void updateMozaics ();

    // Factory related-----------------
    void setup_factories();
    bool check_if_empty();
    void leftovers_to_centre(char colour, int factory);
    void populate_factories();

    // Tilebag related-----------------
    TileBag* tilebag;

    // Round related-------------------
    void process_rounds();
    bool process_turn();
    bool first_tile_taken;
    void endRound();

    std::vector <Turn *> turns;
};


#endif // GAME_MANAGER_H
