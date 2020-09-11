#include "Tile.h"
#include <iostream>
#include <string>

#ifndef FACTORY_H
#define FACTORY_H
#define FACTORY_MAX 4

class TileNode {
public:
   TileNode(Tile* tile, TileNode* next);

   Tile* tile;
   TileNode* next;
};

class Factory {
    public:
        Factory(int num);
        ~Factory();

        int size();
        Tile* get(int index);
        void addBack(Tile* tile);
        void addFront(Tile* tile);
        void removeBack();
        void removeFront();
        void clear();
        void removeFromFactory(char tile);
        int numOfColour(char tile);

        void toString();

    private:
        int factoryNum;
        TileNode* head;
};

#endif // FACTORY_H