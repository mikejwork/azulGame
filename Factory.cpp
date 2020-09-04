#include "Factory.h"
#include <iostream>
#include <cstdarg>

Factory::Factory(int num) :
    factoryNum(num),
    length(0)
{

}

Factory::~Factory() {
    
}

void Factory::addTile(Tile* tile) {
    tile = new Tile(*tile);
    tiles[length] = tile;
    length++;
}

void Factory::toString() {
    std::cout << factoryNum << ": "; 
    for (int i = 0; i < length; i++) {
        std::cout << tiles[i]->getIdentifier() << " ";
    }
    std::cout << std::endl;
}