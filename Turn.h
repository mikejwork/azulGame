#ifndef TURN_H
#define TURN_H

#include <string>

// This class represents the input information for a turn.
// It's meant for data storage, not to have extra functionality added.

class Turn
{
public:
    Turn (
        int factory,
        int row,
        char colour);

    int factory ();
    int row ();
    int colour ();

    std::string toString ();

private:
    int _factory;
    int _row;
    int _colour;
};


#endif
