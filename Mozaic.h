#ifndef MOZAIC_H
#define MOZAIC_H

#define NUM_ROWS 5
#define NUM_COLS 5
#define MIN_ROWS 0

#define BACK 1
#define TOP 2
#define LEFT 3
#define RIGHT 4

#define MOZAIC_WIDTH 5
#define MOZAIC_HEIGHT 5

#include "Tile.h"
#include "TileBag.h"
#include "Row.h"

#include <vector>
#include <iostream>
#include <string>

// TODO make members private
class Mozaic
{
public:
    Mozaic();
    ~Mozaic();

    friend std::ostream &operator<<(
        std::ostream &stream,
        Mozaic &mozaic);

    void add_tiles(int amount, int row, Tile *tile);

    void update_mozaic();
    void update_points(int row_num, int i);

    int get_player_points();

    void firstTileTaken();

    bool check_line(char colour, int row);

    void return_broken(TileBag *tilebag);

private:
    Tile *mozaic[MOZAIC_HEIGHT][MOZAIC_WIDTH];
    std::vector<Row *> rows;
    std::vector<Tile *> broken;

    // BRADEN
    char mask[MOZAIC_HEIGHT][MOZAIC_WIDTH] = {{'B', 'Y', 'R', 'U', 'L'},
                                              {'L', 'B', 'Y', 'R', 'U'},
                                              {'U', 'L', 'B', 'Y', 'R'},
                                              {'R', 'U', 'L', 'B', 'Y'},
                                              {'Y', 'R', 'U', 'L', 'B'}};

    int count(int row_num, int i);
    int player_points;
    bool returnCheck(int row_num, int i, int a);
    int broken_tiles_score();

};

#endif // MOZAIC_H
