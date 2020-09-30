#include "Game_manager.h"

#define NUM_PLAYERS 2
#define NUM_FACTORIES 6
#define MAX_TILES 4

Game_manager::Game_manager()
{
    // TODO - move I/O code
    std::cout << "\nStarting a new game \n \n";
    setup_players();
    setup_factories();
    std::cout << "Let's Play! \n";
}

Game_manager::~Game_manager()
{
    // change into destructors
    players.clear();
    factories.clear();
}

// Factory related methods

void Game_manager::setup_factories()
{
    // Setup the tile bag
    tilebag = new TileBag();
    std::string tiles = "YBBRRRLBULULRYBLBBLYRRUYUYUYUBBRLUBLRYLBLBUBUBRYRLLLRRUBYYBYYLRLRRYBURRLUYYYBUBLRUUBYLLBYYUULURYRUUL"; // Tiles, 20 of each colour, 100 total
    for (std::string::size_type i = 0; i < tiles.size(); i++) {
        Tile* new_tile = new Tile(tiles[i]);
        tilebag->add_back(new_tile);
    }

    //Setup each factory with 4 tiles, taken from the front of the tilebag

    // Setup the centre factory
    factories.push_back(new Factory(0));
    factories[0]->add_tile(new Tile('F'));
    // Setup factories 1-5
    for (int i = 1; i < NUM_FACTORIES; i++)
    {
        factories.push_back(new Factory(i));
        for (int t = 0; t < MAX_TILES; t++)
        {
            factories[i]->add_tile(tilebag->get(0));
            tilebag->remove_front();
        }
    }
}

std::string Game_manager::print_factories()
{
    std::string returnValue = "";

    for (std::string::size_type i = 0; i < factories.size(); i++)
    {
        returnValue += factories[i]->get_number() + ": ";
        for (std::string::size_type e = 0; e < factories[i]->tiles.size(); e++)
        {
            returnValue += factories[i]->tiles[e]->get_colour() + " ";
        }
        returnValue += '\n';
    }
    returnValue += '\n';

    return returnValue;
}

bool Game_manager::check_if_empty()
{
    bool empty = true;

    for (std::string::size_type i = 0; i < factories.size(); i++)
    {
        if (factories[i]->tiles.size() != 0)
        {
           empty = false;
        }
    }

    return empty;
}

// Player related methods

void Game_manager::setup_players()
{
    for (int i = 1; i <= NUM_PLAYERS; i++)
    {
        std::string player_name;
        std::cout << "Enter a name for player " << i << std::endl << "> ";
        std::cin >> player_name;
        std::cout << "\n";

        add_player(new Player(player_name));

    }
}

void Game_manager::add_player(Player* player)
{
    players.push_back(player);
}

Player* Game_manager::get_next_player()
{
    return players[player_turn];
}

void Game_manager::cycle_players()
{
    player_turn++;
    if (player_turn >= (int)players.size())
    {
        player_turn = 0;
    }
}

// Returns points
int Game_manager::turn(Turn * turn)
{
    Player * player = get_next_player ();
    Mozaic * mozaic = player->get_mozaic ();

    int factory = turn->factory ();
    int row = turn->row ();
    int colour = turn->colour ();

    // get the amount of the chosen colour in the factory
    int amount = factories[factory]->get_amount(colour);

    mozaic->add_tiles(amount, row, new Tile(colour));
    if (factory == 0)
    {
        if (!first_tile_taken)
        {
            mozaic->broken.push_back(new Tile('F'));
            factories[factory]->remove_specific('F');
            first_tile_taken = true;
        }
        factories[factory]->remove_specific(colour);
    } else {
        leftovers_to_centre(colour, factory);
        factories[factory]->clear();
    }

    // TODO - NEED TO MOVE TO END OF ROUND
    mozaic->update_mozaic();
    player->add_points(mozaic->get_player_points());

    cycle_players();

    return player->get_points ();
}

void Game_manager::leftovers_to_centre(char colour, int factory)
{
    for (std::string::size_type i = 0; i < factories[factory]->tiles.size(); i++)
    {
        if (factories[factory]->tiles[i]->get_colour() != colour)
        {
            factories[0]->add_tile(new Tile(*factories[factory]->tiles[i]));
        }
    }
}

bool Game_manager::factoriesEmpty ()
{
    return this->check_if_empty ();
}
