#include "game_manager.h"

#define NUM_PLAYERS 2
#define NUM_FACTORIES 6
#define MAX_TILES 4
#define MAX_ROUNDS 5

Game_manager::Game_manager()
{
    std::cout << "\nStarting a new game \n \n";
    setup_players();
    setup_factories();
    std::cout << "Let's Play! \n";
    
    // Loop for 5 rounds
    process_rounds();
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

void Game_manager::print_factories()
{   
    std::cout << "Factories: \n";
    for (std::string::size_type i = 0; i < factories.size(); i++)
    {
        std::cout << factories[i]->get_number() << ": ";
        for (std::string::size_type e = 0; e < factories[i]->tiles.size(); e++)
        {
            std::cout << factories[i]->tiles[e]->get_colour() << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool Game_manager::check_if_empty()
{
    bool not_empty = true;
    int count = 0;

    for (std::string::size_type i = 0; i < factories.size(); i++)
    {
        if (factories[i]->tiles.size() == 0)
        {
           count++;
        }
    }
    if (count == 6)
    {
        not_empty = false;
    }

    return not_empty;
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

// Round related methods

void Game_manager::process_rounds() // All we have to do for loading save file is make another function like this but dont include the printing methods, just get straight input. ezpz
{ 
    for (int i = 0; i < MAX_ROUNDS; i++)
    {
        first_tile_taken = false;
        while (check_if_empty() /* Check if factories empty, if so then end the round. */) {
            std::cout << "\n=== Start Round === \n" << 
            // Print the current player turn
            "Turn for player: " << get_next_player()->get_name() << "\n";
            print_factories();

            // Print the current player mozaic
            std::cout << "Mozaic for: " << get_next_player()->get_name() << "\n";
            get_next_player()->get_mozaic()->print_mozaic();

            process_turn();
            get_next_player()->get_mozaic()->update_mozaic(); //NEED TO MOVE TO END OF ROUND
            get_next_player()->add_points(get_next_player()->get_mozaic()->get_player_points()); //NEED TO MOVE TO END OF ROUND
            std::cout << "PLAYER POINTS: " << get_next_player()->get_points() << std::endl; //NEED TO REMOVE OR PLACE SOMEWHERE ELSE
            cycle_players();
        }
    }
}

bool Game_manager::process_turn()
{
    bool status = false;
    
    std::cout << "> ";
    std::istream & in = std::cin;
    std::string cmd; // command

    in >> cmd; // get the command string input
    if (cmd == "turn")
    {
        int factory;
        int row;
        char colour;

        in >> factory;
        in >> colour;
        in >> row;

        if (colour == 'F')
        {
            std::cout << "you cannot move the 'F' tile! \n";
            status = false;
        }

        turn(factory, colour, row);
    }

    return status;
}

bool Game_manager::turn(int factory, char colour, int row)
{
    bool status = false;
    
    // get the amount of the chosen colour in the factory
    int amount = factories[factory]->get_amount(colour);

    get_next_player()->get_mozaic()->add_tiles(amount, row, new Tile(colour));
    if (factory == 0)
    {
        if (!first_tile_taken) 
        {
            get_next_player()->get_mozaic()->broken.push_back(new Tile('F'));
            factories[factory]->remove_specific('F');
            first_tile_taken = true;
        }
        factories[factory]->remove_specific(colour);
    } else {
        leftovers_to_centre(colour, factory);
        factories[factory]->clear();
    }

    return status;
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