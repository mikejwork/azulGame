#ifndef TILEBAG_H
#define TILEBAG_H
#include "tile.h"
#include <iostream>

class Node {
public:
   Node(Tile* tile, Node* next);

   Tile* tile;
   Node* next;
};

class TileBag {
public:
   TileBag();
   ~TileBag();

   int get_size();
   Tile* get(int index);
   void add_back(Tile* tile);
   void remove_front();

   
   void toString();

private:
   int size;
   Node* head;
};

#endif // TILEBAG_H