#include "TileBag.h"

Node::Node(Tile* tile, Node* next) :
   tile(tile),
   next(next)
{}

TileBag::TileBag() {}

TileBag::TileBag(TileBag& other) 
{
   // TODO
}

TileBag::~TileBag() {
   // TODO
}

int TileBag::size() {
   int count = 0;
   Node* current = head;
   while (current != nullptr) {
       ++count;
       current = current->next;
   }
   return count;
}

Tile* TileBag::get(int index) {
   int count = 0;
   Node* current = head;
   Tile* tile = new Tile('?');
   if (index >= 0 && index < size()) {
       while (count < index) {
            ++count;
            current = current->next;
       }
       tile = current->tile;
   }
   return tile;
}

void TileBag::addFront(Tile* tile) {
   Node* newNode = new Node(tile, head);
   head = newNode;
}

void TileBag::addBack(Tile* tile) {
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
}

void TileBag::removeBack() {
   if (head != nullptr) {
      if (head->next == nullptr) {
         head = nullptr;
      }

      Node* temp = head;
      while (temp->next->next != nullptr) {
         temp = temp->next;
      }
 
      temp->next = nullptr;
   }
}

void TileBag::removeFront() {
   if (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
   }
}

void TileBag::clear() {
   head = nullptr;
}
