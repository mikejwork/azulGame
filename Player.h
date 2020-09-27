#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "mozaic.h"

class Player
{
public:
    Player(std::string name);
    ~Player();

    std::string get_name();
    Mozaic* get_mozaic();

private:
    std::string name;
    Mozaic* mozaic;

};

#endif // PLAYER_H