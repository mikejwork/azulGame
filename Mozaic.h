#include "Tile.h"
#include <iostream>
#include <vector>

#ifndef MOZAIC_H
#define MOZAIC_H

class Mozaic {
public:
    Mozaic();
    ~Mozaic();

    Tile* mozaic[5][5];
    Tile* pattern_lines[5][5];
    Tile* broken[0]; // Broken tiles array
    std::vector<Tile*> vecBroken;

    bool placeTiles(Tile* tile, int row, int count);
    void init();
    void printMozaic();
private:
};

#endif // MOZAIC_H