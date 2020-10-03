#include "TileBag.h"

#define DEFAULT_TILES "YBBRRRLBULULRYBLBBLYRRUYUYUYUBBRLUBLRYLBLBUBUBRYRLLLRRUBYYBYYLRLRRYBURRLUYYYBUBLRUUBYLLBYYUULURYRUUL"

Node::Node(Tile* tile, Node* next) :
   tile(tile),
   next(next)
{}

TileBag::TileBag() {
   size = 0;
   this->startingTiles = DEFAULT_TILES;
   loadTiles (startingTiles);
}

TileBag::TileBag(std::string startingTiles) {
   size = 0;
   this->startingTiles = startingTiles;
   loadTiles (startingTiles);
}

TileBag::~TileBag()
{
   // TODO - memory leak here
}

void TileBag::loadTiles (std::string tiles)
{
    for (std::string::size_type i = 0; i < tiles.size(); i++) {
        Tile* new_tile = new Tile(tiles[i]);
        add_back(new_tile);
    }
}

int TileBag::get_size()
{
   return this->size;
}

Tile* TileBag::get(int index)
{
   int count = 0;
   Node* current = head;
   Tile* tile = nullptr;
   if (index >= 0 && index < size)
   {
       while (count < index) {
            ++count;
            current = current->next;
       }
       tile = new Tile(*current->tile);
   }
   return tile;
}

void TileBag::add_back(Tile* tile) {
   Node* toAdd = new Node(tile, nullptr);

   if (head == nullptr)
   {
      head = toAdd;
   }
   else
   {
      Node* current = head;
      while (current->next != nullptr) {
         current = current->next;
      }
      current->next = toAdd;
   }
   size++;
}

void TileBag::remove_front() {
   if (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
   }
   size--;
}

std::string TileBag::getStartingTiles ()
{
    return this->startingTiles;
}

std::string TileBag::toString()
{
   std::string str = "";

   Node* current = head;
   while (current != nullptr)
   {
      str += current->tile->get_colour();
       current = current->next;
   }

   return str;
}
