#include <iostream>
#include <string>
#include "Factory.h"

#define MAX_ROUNDS 5

class GameManager {
public:
    GameManager();
    GameManager(int saveFile);
    ~GameManager();
private:
    std::string playerOne;
    std::string playerTwo;
    std::string playerTurn;
    int currentRound;
    
    Factory* zero;
    Factory* one;
    Factory* two;
    Factory* three;
    Factory* four;
    Factory* five;

    void initPlayerNames();
    void newRound();
    void printFactories();
    void setupFactories();
};