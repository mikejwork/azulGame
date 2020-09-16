#include "Player.h"

Player::Player(std::string name) :
   name(name)
{
   this->mozaic = new Mozaic ();
}

Player::~Player ()
{
   delete this->mozaic;
}

std::string Player::getName ()
{
    return this->name;
}

Mozaic * Player::getMozaic ()
{
    return this->mozaic;
}
