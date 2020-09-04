#include "Tile.h"

Tile::Tile(char identifier) :
    identifier(identifier)
{

}

Tile::Tile(const Tile& other) :
    identifier(other.identifier)
{

}

Tile::~Tile() {

}

char Tile::getIdentifier() {
    return identifier;
}