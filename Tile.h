#ifndef TILE_H
#define TILE_H

class Tile
{
public:
    Tile(char colour);
    Tile(const Tile& other);
    ~Tile();

    char get_colour();

private:
    char colour;
};  

#endif // TILE_H