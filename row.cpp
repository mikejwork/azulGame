#include "row.h"

Row::Row() 
{
    size = 0;
}

Row::~Row()
{}

Tile* Row::get_index(int index)
{
    return tiles.at(index);
}

int Row::get_size()
{
    return this->size;
}

void Row::add(Tile* tile)
{
   tiles.push_back(new Tile(*tile));
   size++;
}

void Row::clear_row() {
    tiles.clear();
    size = 0;
}