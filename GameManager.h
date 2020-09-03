#include <iostream>
#include <string>

#define MAX_ROUNDS 5

class GameManager {
public:
    GameManager();
    GameManager(int saveFile);
    ~GameManager();

    void initGame();

private:
    std::string first_name;
    std::string last_name;
    int currentRound;
};