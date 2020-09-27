#include "mozaic.h"

Mozaic::Mozaic()
{
    // add the five rows to the mozaic
    for (int i = 0; i < 5; i++)
    {
        rows.push_back(new Row());
    }

    // rows[3]->add(new Tile('F'));
    // rows[3]->add(new Tile('U'));
    // rows[3]->add(new Tile('C'));
    // rows[3]->add(new Tile('K'));
}

Mozaic::~Mozaic()
{
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int x = 0; x < NUM_ROWS; x++)
        {
            mozaic[i][x] = nullptr;
        }
    }
}

void Mozaic::print_mozaic()
{
    int row_num = 1;
    int blank_space = 4;
    for (int row = 1; row < 6; row++)
    {
        std::cout << row << ":";
        for (int spacing = 0; spacing < blank_space; spacing++)
        {
            std::cout << "  "; //Prints the empty space
        }

        int empty = row_num - rows[row_num - 1]->get_size();
        for (int index = 0; index < empty; index++)
        {
            std::cout << " ."; //Prints the amount of dots for that row
        }

        for (int index = 0; index < rows[row_num - 1]->get_size(); index++)
        {
            std::cout << " " << rows[row_num - 1]->get_index(index)->get_colour(); //Places the tile colour
        }
        blank_space--;
        row_num++;

        std::cout << " ||";
        for (int i = 0; i < 5; i++)
        { //need to change 5
            if (mozaic[row - 1][i] == nullptr)
            {
                std::cout << " .";
            }
            else
            {
                std::cout << " " << mozaic[row - 1][i]->get_colour();
            }
        }
        std::cout << "\n";
    }

    std::cout << "broken: ";

    for (std::string::size_type i = 0; i < broken.size(); i++)
    {
        std::cout << broken[i]->get_colour() << " ";
    }
    std::cout << "\n";
}

void Mozaic::update_mozaic()
{
    int row_num = 1;
    for (int row = 0; row < NUM_ROWS; row++)
    {
        int size = row_num - rows[row_num - 1]->get_size(); //size will return the value of how many empty spaces are in the row
        if (size == 0)
        {
            for (int i = 0; i < NUM_ROWS; i++)
            {
                if (rows[row_num - 1]->get_index(row)->get_colour() == mask[row][i]) 
                {
                    mozaic[row_num - 1][i] = new Tile(rows[row_num - 1]->get_index(row)->get_colour());
                }
            }
            rows[row_num - 1]->clear_row();
        }
        row_num++;
    }
}




void Mozaic::add_tiles(int amount, int row, Tile *tile)
{
    for (int i = 0; i < amount; i++)
    {
        rows[row - 1]->add(new Tile(*tile));
    }
}