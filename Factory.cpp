#include "Factory.h"

TileNode::TileNode(Tile* tile, TileNode* next) :
   tile(tile),
   next(next)
{}

Factory::Factory(int num) :
    factoryNum(num)
{}

Factory::~Factory() {
    // TODO
}

int Factory::size() {
    int count = 0;
    TileNode* current = head;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

Tile* Factory::get(int index) {
   int count = 0;
   TileNode* current = head;
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

void Factory::addFront(Tile* tile) {
   TileNode* newNode = new TileNode(tile, head);
   head = newNode;
}

void Factory::addBack(Tile* tile) {
   TileNode* toAdd = new TileNode(tile, nullptr);

   if (head == nullptr) {
      head = toAdd;
   } else {
      TileNode* current = head;
      while (current->next != nullptr) {
         current = current->next;
      }  
      current->next = toAdd;
   }
}

void Factory::removeBack() {
   if (head != nullptr) {
      if (head->next == nullptr) {
         head = nullptr;
      }

      TileNode* temp = head;
      while (temp->next->next != nullptr) {
         temp = temp->next;
      }
 
      temp->next = nullptr;
   }
}

void Factory::removeFront() {
   if (head != nullptr) {
      TileNode* temp = head;
      head = head->next;
      delete temp;
   }
}

void Factory::clear() {
   head = nullptr;
}


void Factory::toString() {
   std::cout << factoryNum << ": "; 
   TileNode* current = head;
   while (current != nullptr) {
      std::cout << current->tile->getIdentifier() << " ";
      current = current->next;
   }
   std::cout << "\n";
}

int Factory::numOfColour(char tile) {
   int count = 0;
   TileNode* current = head;
   while (current != nullptr) {
      if (current->tile->getIdentifier() == tile) {
         count++;
      }
      current = current->next;
   }
   return count;
}

void Factory::removeFromFactory(char tile) {
   struct TileNode *prev, *cur;

   while (head != nullptr && head->tile->getIdentifier() == tile) {
      prev = head;
      head = head->next;
      free(prev);
   }

   prev = nullptr;
   cur = head;

   while (cur != nullptr) {
      if (cur->tile->getIdentifier() == tile) {
         if (prev != nullptr) {
            prev->next = cur->next;
         }
         free(cur);
         cur = prev->next;
      } else {
         prev = cur;
         cur = cur->next;
      }
   }
}