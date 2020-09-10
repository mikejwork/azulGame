#include "Tile.h"
#include <iostream>

class Mozaic {
public:
    Mozaic();
    ~Mozaic();

    Tile* mozaic[5][5];
    Tile* pattern_lines[5][5];
    Tile* broken[7]; // Broken tiles array

    void placeTiles(Tile* tile, int row, int count);
    void init();
    void printMozaic();
private:
};