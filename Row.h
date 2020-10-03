#ifndef ROW_H
#define ROW_H

#include <vector>

#include "Tile.h"

class Row
{
public:
    Row();
    ~Row();
    bool empty = true;

    int get_size();
    std::vector<Tile*> tiles;
    Tile* get_index(int index);

    void add(Tile* tile);
    void clear_row();

private:
    int size;
};

#endif //ROW_H
