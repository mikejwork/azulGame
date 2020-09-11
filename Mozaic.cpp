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
    std::cout << "broken: ";
    for (std::size_t i = 0; i < vecBroken.size(); i++) {
        std::cout << vecBroken[i]->getIdentifier() << " ";
    }
    std::cout << "\n \n";
}

void Mozaic::init() {
    Tile* empty = new Tile('.');
    int blank = 4;
    int dots = 1;
    for (int i = 0; i < 5; i++) {
        for (int ii = 0; ii < 5; ii++) {
            mozaic[i][ii] = empty;
        }
        for (int j = 0; j < blank; j++) {
            pattern_lines[i][j] = new Tile('?'); // Setting this value to ? because it isnt seen and i need something that isnt just a dot to check for clear spaces.
        }
        for (int k = 0; k < dots; k++) {
             pattern_lines[i][k + blank] = new Tile('.');
        }
        blank--;
        dots++;
    }
}

bool Mozaic::placeTiles(Tile* tile, int row, int count) {
    Tile* newTile = new Tile(*tile);
    bool isSuccessful = true;
    bool rowEmpty = true;
    char rowColour = ' ';
    int space = 0;
    int tiles = 0;

    if (pattern_lines[row - 1][4]->getIdentifier() != '.') {
        rowEmpty = false;
        rowColour = pattern_lines[row - 1][4]->getIdentifier();
    }

    if (!rowEmpty) {
        if (tile->getIdentifier() != rowColour) {
            std::cout << "The colour " << rowColour << " is already in that row" << std::endl;
            isSuccessful = false;
        }
    }
    if (isSuccessful) {
        for (int i = 0; i < 5; i++) {
            if (pattern_lines[row - 1][4 - i]->getIdentifier() == '.') {
                space++;
            } else if (pattern_lines[row - 1][4 - i]->getIdentifier() != '?') {
                tiles++;
            }
        }

        int numBroken;
        if (count > space) {
            numBroken = count - space;
            count = space;
            for (int i = 0; i < numBroken; i++) {
                vecBroken.push_back(tile);
            }
        }
    }

    if (space == 0) {
        std::cout << "Not enough space for move!" << std::endl;
        isSuccessful = false;
    }
    if (isSuccessful) {
        for (int i = 0; i < count; i++) {
            pattern_lines[row - 1][4 - i - tiles] = newTile;
        }
    }
    return isSuccessful;
}