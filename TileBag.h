#ifndef TILEBAG_H
#define TILEBAG_H

#include "Tile.h"

#include <iostream>
#include <string>

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


   std::string toString();

private:
   int size;
   Node* head;
};

#endif // TILEBAG_H
