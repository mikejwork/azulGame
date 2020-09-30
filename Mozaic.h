#ifndef MOZAIC_H
#define MOZAIC_H

#define NUM_ROWS 5
#define MIN_ROWS 0
#define BACK 1
#define TOP 2
#define LEFT 3
#define RIGHT 4

#include "tile.h"
#include "row.h"
#include <vector>
#include <iostream>

class Mozaic
{
public:
    Mozaic();
    ~Mozaic();

    Tile* mozaic[5][5];
    std::vector<Row*> rows;
    std::vector<Tile*> broken;

    void print_mozaic();

    void add_tiles(int amount, int row, Tile* tile);

    // BRADEN
    char mask[5][5] = {{'B', 'Y', 'R', 'U', 'L'},
                       {'L', 'B', 'Y', 'R', 'U'},
                       {'U', 'L', 'B', 'Y', 'R'},
                       {'R', 'U', 'L', 'B', 'Y'},
                       {'Y', 'R', 'U', 'L', 'B'}};
    void update_mozaic();
    void update_points(int row_num, int i);

    int get_player_points();


private:

    int broken_tiles_score();

    int count(int row_num, int i);
    int player_points;
    bool returnCheck(int row_num, int i, int a);
};

#endif // MOZAIC_H