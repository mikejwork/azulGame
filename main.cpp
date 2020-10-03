#include "menu.h"

void usage();

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        // Normal mode - open menu
        Menu* menu = new Menu();
        menu->display_menu();
    }
    else if (argc == 3)
    {
        // Testing mode
        std::string flag ( argv[1]);
        std::string filename (argv [2]);

        // TODO implement testing mode
    }
    else
    {
        usage ();
    }
}

void usage ()
{
    std::cout << "Usage:" << std::endl;
    std::cout << "\tazul" << std::endl;
    std::cout << "\tOR" << std::endl;
    std::cout << "\tazul -t < filename" << std::endl;
}
