#include "player.h"

Player::Player(std::string name) :
    name(name)
{
    this->mozaic = new Mozaic();
}    

Player::~Player()
{
    delete this->mozaic;
}

std::string Player::get_name()
{
    return this->name;
}

Mozaic* Player::get_mozaic()
{
    return this->mozaic;
}