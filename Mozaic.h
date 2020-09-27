#ifndef MOZAIC_H
#define MOZAIC_H

#define NUM_ROWS 5

#include "tile.h"
#include "row.h"
#include <vector>
#include <iostream>

class Mozaic
{
public:
    Mozaic();
    ~Mozaic();

    Tile *mozaic[5][5];
    char mask[5][5] = {{'B', 'Y', 'R', 'U', 'L'},
                       {'L', 'B', 'Y', 'R', 'U'},
                       {'U', 'L', 'B', 'Y', 'R'},
                       {'R', 'U', 'L', 'B', 'Y'},
                       {'Y', 'R', 'U', 'L', 'B'}};

    std::vector<Row *> rows;
    std::vector<Tile *> broken;

    void print_mozaic();

    void update_mozaic();

    void add_tiles(int amount, int row, Tile *tile);

private:
};

#endif // MOZAIC_H