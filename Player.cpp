#include "player.h"

Player::Player(std::string name) : name(name)
{
    this->mozaic = new Mozaic();
}

Player::~Player()
{
    delete this->mozaic;
}

int Player::get_points()
{
    return this->total_points;
}

void Player::add_points(int points)
{
    this->total_points += points;
}

std::string Player::get_name()
{
    return this->name;
}

Mozaic *Player::get_mozaic()
{
    return this->mozaic;
}