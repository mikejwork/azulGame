#include "Mozaic.h"


Mozaic::Mozaic() {
    init();
}

Mozaic::~Mozaic() {
    
}

void Mozaic::printMozaic() {
    int blank = 4;
    int dots = 1;
    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << ":";
        for (int j = 0; j < blank; j++) {
            std::cout << "  ";
        }
        for (int k = 0; k < dots; k++) {
            std::cout << " " << pattern_lines[i][k + blank]->getIdentifier();
        }
        blank--;
        dots++;
        std::cout << " || ";
        for (int ii = 0; ii < 5; ii++) {
            std::cout << mozaic[i][ii]->getIdentifier() << " ";
        }
        std::cout << std::endl;
    }
}

void Mozaic::init() {
    Tile* empty = new Tile('.');
    for (int i = 0; i < 5; i++) {
        for (int ii = 0; ii < 5; ii++) {
            mozaic[i][ii] = empty;
        }

    
        // int e = 5; e > 0; e--
        for (int h = 0; h < 5; h++) {
            pattern_lines[i][h] = new Tile('d');
        }

    }


}

void Mozaic::placeTiles(Tile* tile, int row, int count) {
    // int maximum = row; // The maximum number the pattern_line can hold
    // tile = new Tile(*tile);
    int leftOver = count - row;
    int t = count;
    if (leftOver > 0) { // if there are leftovers, send to broken tile section.
        t = t - leftOver; // Subtract broken tiles and continue;
        std::cout << "leftover" << std::endl;
    }

    for (int i = 0; i < t; i++) {
        pattern_lines[row][4 - i] = tile;
        
    }
}