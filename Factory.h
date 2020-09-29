#ifndef FACTORY_H
#define FACTORY_H
#include "tile.h"
#include <vector>
#include <string>


class Factory
{
public:
    Factory(int factory_number);
    ~Factory();

    int get_number();

    void add_tile(Tile* tile);
    void remove_specific(char colour);
    void clear();
    int get_amount(char c);

    std::vector<Tile*> tiles;

    bool empty = false;

private:
    int factory_number;
};  

#endif // FACTORY_H