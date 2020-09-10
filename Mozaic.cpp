#include "Mozaic.h"
#include "Tile.h"

class Mozaic {
public:
    Mozaic();
    ~Mozaic();

    Tile* mozaic[5][5];
    Tile* pattern_lines[5][5];
    Tile* broken[7]; // Broken tiles array

    void addTile(Tile* tile, int row);

private:
};