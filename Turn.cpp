#include "Turn.h"

// This class represents the input information for a turn.
// It's meant for data storage, not to have extra functionality added.

Turn::Turn (
    int factory,
    int row,
    char colour)
{
    this->_factory = factory;
    this->_row = row;
    this->_colour = colour;
}

int Turn::factory ()
{
    return this->_factory;
}

int Turn::row ()
{
    return this->_row;
}

int Turn::colour ()
{
    return this->_colour;
}

std::string Turn::toString ()
{
    std::string str = "turn ";
    str += _factory + " ";
    str += _row + " ";
    str += _colour + "\n";

    return str;
}
