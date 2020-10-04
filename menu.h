#ifndef MENU_H
#define MENU_H
#include <iostream>

#include "Game_manager.h"

class Menu {
public:
    Menu();

    void display_menu();
    void display_credits();
    void input_logic(int input);

    bool loadGame ();
    void playGame ();
private:
    // TODO I reckon we should get rid of this var and just keep the game on the
    // TODO stack, but this isn't important.
    Game_manager* game_manager;
};

#endif // MENU_H
