#include "Tile.h"

#define FACTORY_MAX 4

class Factory {
    public:
        Factory(int num);
        ~Factory();

        void toString();
        void addTile(Tile* tile);

    private:
        Tile* tiles[FACTORY_MAX];
        int factoryNum;
        int length;
};