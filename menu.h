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
private:
    Game_manager* game_manager;
};

#endif // MENU_H
