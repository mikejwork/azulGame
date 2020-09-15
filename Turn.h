#ifndef TURN_H
#define TURN_H

class Turn
{
public:
    Turn (int factory, char colour, int row);

    int getFactory ();
    char getColour ();
    int getRow ();

private:
    int factory;
    char colour;
    int row;
};

#endif
