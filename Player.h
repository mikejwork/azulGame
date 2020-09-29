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
    int get_points();
    void add_points(int points);
private:
    std::string name;
    Mozaic* mozaic;
    int total_points;
};

#endif // PLAYER_H