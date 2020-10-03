#include "Factory.h"

#define MAX_TILES 4

Factory::Factory(int factory_number) :
    factory_number(factory_number)
{}

Factory::~Factory() {}

int Factory::get_number()
{
    return this->factory_number;
}

void Factory::add_tile(Tile* tile)
{
    // Create deep copy and add to back
    tiles.push_back(new Tile(*tile));
}

void Factory::clear()
{
    tiles.clear();
    empty = true;
}

int Factory::get_amount(char colour)
{
    int count = 0;
    for (std::string::size_type i = 0; i < tiles.size(); i++)
    {
        if (tiles[i]->get_colour() == colour) {
            count++;
        }
    }
    return count;
}

void Factory::remove_specific(char colour)
{
    std::vector<Tile*> tiles_cpy;
    for (std::string::size_type i = 0; i < tiles.size(); i++)
    {
        if (tiles[i]->get_colour() != colour) {
            tiles_cpy.push_back(tiles[i]);
        }
    }
    tiles = tiles_cpy;
}
