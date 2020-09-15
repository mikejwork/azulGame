#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Mozaic.h"

class Player {
public:
   Player (std::string name);
   ~Player ();

   std::string getName ();
   Mozaic * getMozaic ();

private:
   std::string name;
   Mozaic* mozaic;
};

#endif
