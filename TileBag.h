#include <iostream>
#include <fstream>
#include "Tile.h"


#ifndef TILEBAG_H
#define TILEBAG_H

class Node {
public:
   Node(Tile* tile, Node* next);

   Tile* tile;
   Node* next;
};

class TileBag {
public:
   TileBag();
   TileBag(TileBag& other);
   ~TileBag();

   int size();
   Tile* get(int index);
   void addBack(Tile* tile);
   void addFront(Tile* tile);
   void removeBack();
   void removeFront();
   void clear();

private:

   Node* head;
};

#endif // TILEBAG_H
