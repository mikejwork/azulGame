#include "TileBag.h"

Node::Node(Tile* tile, Node* next) :
   tile(tile),
   next(next)
{}

TileBag::TileBag() {
   size = 0;
}

TileBag::~TileBag()
{
   // TODO
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

   if (head == nullptr) {
      head = toAdd;
   } else {
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

void TileBag::toString()
{
   Node* current = head;
   while (current != nullptr)
   {
      std::cout << current->tile->get_colour();
       current = current->next;
   }
   std::cout << "\n";
}
