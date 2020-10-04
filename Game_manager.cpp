#include "Game_manager.h"

#define NUM_PLAYERS 2
#define NUM_FACTORIES 6
#define MAX_TILES 4

Game_manager::Game_manager()
{
    this->tilebag = new TileBag();

    // TODO - move I/O code
    std::cout << "\nStarting a new game \n \n";
    setup_players();
    setup_factories();
    std::cout << "Let's Play! \n";
}

Game_manager::Game_manager (std::string startingTileBag)
{
    this->tilebag = new TileBag (startingTileBag);
    setup_factories();
}

Game_manager::~Game_manager()
{
    // change into destructors
    players.clear ();
    factories.clear ();
    turns.clear ();
    delete tilebag;
}

// Factory related methods

void Game_manager::setup_factories()
{

    //Setup each factory with 4 tiles, taken from the front of the tilebag

    // Setup the centre factory
    factories.push_back(new Factory(0));
    // Setup factories 1-5
    for (int i = 1; i < NUM_FACTORIES; i++)
    {
        factories.push_back(new Factory(i));
    }
    populate_factories();
}

void Game_manager::populate_factories()
{
    factories[0]->add_tile(new Tile('F'));
    for (int i = 1; i < NUM_FACTORIES; i++)
    {
        for (int t = 0; t < MAX_TILES; t++)
        {
            factories[i]->add_tile(tilebag->get(0));
            tilebag->remove_front();
        }
    }
}

void Game_manager::print_factories(std::ostream & stream)
{
    for (std::string::size_type i = 0; i < factories.size(); i++)
    {
        stream << factories[i]->get_number() << ": ";
        for (std::string::size_type e = 0; e < factories[i]->tiles.size(); e++)
        {
            stream << factories[i]->tiles[e]->get_colour() << " ";
        }
        stream << std::endl;
    }
    stream << std::endl;
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

int Game_manager::numPlayers ()
{
    return (int) this->players.size ();
}

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
    turns.push_back (turn);

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
            mozaic->firstTileTaken ();
            factories[factory]->remove_specific('F');
            first_tile_taken = true;
        }
        factories[factory]->remove_specific(colour);
    } else {
        leftovers_to_centre(colour, factory);
        factories[factory]->clear();
    }

    if (factoriesEmpty ())
    {
        finish_update(); // Initiates the final calculations needed for that round - Player Points, move tiles to mozaic
    }
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

std::ostream & operator<< (std::ostream & stream, Game_manager & game)
{
    stream << game.tilebag->getStartingTiles () << std::endl;

    for (int i = 0; i < (int) game.players.size (); i++)
    {
        stream << game.players[i]->get_name() << std::endl;
    }

    for (int i = 0; i < (int) game.turns.size (); i++)
    {
        stream << "turn " << game.turns[i] << std::endl;
    }

    return stream;
}

void Game_manager::finish_update() {

    for (int i = 0; i < (int)players.size(); i++) //this is used just in case there are multiple users - future implement?
    {
        Player *temp = get_next_player();
        temp->get_mozaic()->update_mozaic();
        temp->add_points(temp->get_mozaic()->get_player_points());
        temp->get_mozaic()->return_broken(tilebag);
        cycle_players();
    }
    if (player_turn == 0) //This places player 1 on the top of the Final Score
       {
        cycle_players();
       }
}

std::string Game_manager::return_winner_name() //THIS IS USED TO PRINT THE FINAL SCORES
{
    std::string returnString = "Player " + get_next_player()->get_name() + "wins!\n";
    ;
    for (int i = 0; i < (int)players.size(); i++) //this is used just in case there are multiple users - future implement?
    {
        Player *temp = get_next_player();
        cycle_players();
        if (temp->get_points() > get_next_player()->get_points())
        {
            returnString = "Player " + temp->get_name() + " wins!\n";
        }
        if (temp->get_points() == get_next_player()->get_points())
        {
            returnString = "It's a draw!\n";
        }
    }
    //delete temp; //need to delete temp
    return returnString;
}
