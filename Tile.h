#ifndef TILE_H
#define TILE_H

class Tile {
    public:
        Tile(char identifier);
        Tile(const Tile& other);
        ~Tile();

        char getIdentifier();
    private:
        char identifier;
};

#endif