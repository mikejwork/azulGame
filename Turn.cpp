#include "Turn.h"

Turn::Turn (int factory, char colour, int row)
{
    this->factory = factory;
    this->colour = colour;
    this->row = row;
}

int Turn::getFactory ()
{
    return this->factory;
}

int Turn::getRow ()
{
    return this->row;
}

char Turn::getColour ()
{
    return this->colour;
}
