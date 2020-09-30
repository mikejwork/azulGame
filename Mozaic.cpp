#include "Mozaic.h"

Mozaic::Mozaic()
{
    // add the five rows to the mozaic
    for (int i = 0; i < 5; i++)
    {
        rows.push_back(new Row());
    }
    player_points = 0;
}

Mozaic::~Mozaic()
{}

std::string Mozaic::print_mozaic()
{
    std::string returnValue = "";

    int row_num = 1;
    int blank_space = 4;
    for (int row = 1; row < 6; row++)
    {
        returnValue += row + ":";
        for (int spacing = 0; spacing < blank_space; spacing++)
        {
            returnValue += "  ";
        }

        int empty = row_num - rows[row_num-1]->get_size();
        for (int index = 0; index < empty; index++)
        {
            returnValue += " .";
        }

        for (int index = 0; index < rows[row_num-1]->get_size(); index++)
        {
            char colour = rows[row_num-1]->get_index(index)->get_colour();
            returnValue += " " + colour;
        }
        blank_space--;
        row_num++;

        returnValue += " ||" ;
        for (int i = 0; i < 5; i++)
        {
            if (mozaic[row - 1][i] == nullptr)
            {
                returnValue += " ." ;
            }
            else
            {
                char colour = mozaic[row - 1][i]->get_colour();
                returnValue += " " + colour;
            }

        }

        returnValue += '\n';
    }

    returnValue += "broken: ";

    for (std::string::size_type i = 0; i < broken.size(); i++) {
        returnValue += broken[i]->get_colour() + " ";
    }
    returnValue += '\n';

    return returnValue;
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
                    player_points = count(row_num - 1, i);
                }
            }
            rows[row_num - 1]->clear_row();
        }
        row_num++;
    }
}
int Mozaic::get_player_points() {
    int temp = this->player_points;
    this->player_points = 0;
    return temp;
}


int Mozaic::count(int row_num, int col)
{
    int b = row_num;
    int f = row_num;
    int l = col;
    int r = col;

    int countRight = 0;
    int countTop = 0;
    int countLeft = 0;
    int countBot = 0;
    int result = 1;
    bool once;

    once = true;
    while (!returnCheck(row_num, r, RIGHT))
    {
        if (once == true) {
            countRight = 1;
            once = false;
        }
        countRight++;
        r++;
    }
    once = true;

    while (!returnCheck(row_num, l, LEFT))
    {
        if (once == true) {
            countLeft = 1;
            once = false;
        }
        countLeft++;
        l--;
    }
    once = true;

    while (!returnCheck(b, col, BACK))
    {
        if (once == true) {
            countBot = 1;
            once = false;
        }
        countBot++;
        b++;
    }
    once = true;

    while (!returnCheck(f, col, TOP))
    {
        if (once == true) {
            countTop = 1;
            once = false;
        }
        countTop++;
        f--;
    }
    if (!(countRight + countLeft + countTop + countBot) == 0)
    {
        result = countRight + countLeft + countTop + countBot;
    }

    return result;
}

bool Mozaic::returnCheck(int row_num, int i, int a)
{
    bool ans = true;
    if (a == 1)
    {
        //CHECKS DOWN
        if (row_num + 1 <= 5) //This prevents checking outside of array
        {
            if (mozaic[row_num + 1][i] != nullptr)
            {

                ans = false;
            }
        }
    }
    else if (a == 2)
    {
        //CHECKS UP
        if (row_num - 1 >= 0)
        {
            if (mozaic[row_num - 1][i] != nullptr)
            {

                ans = false;
            }
        }
    }
    else if (a == 3)
    {
        //CHECKS LEFT
        if (i - 1 >= 0)
        {
            if (mozaic[row_num][i - 1] != nullptr)
            {
                ans = false;
            }
        }
    }
    else if (a == 4)
    {
        if (i + 1 <= 5)
        {
            //CHECKS RIGHT
            if (mozaic[row_num][i + 1] != nullptr)
            {
                ans = false;
            }
        }
    }
    return ans;
}

void Mozaic::add_tiles(int amount, int row, Tile* tile)
{
    int tiles_filled = rows[row - 1]->get_size();
    int spaces_left = row - tiles_filled;
    int leftover = 0;

    if (amount > spaces_left)
    {
        leftover = amount - spaces_left;
        for (int i = 0; i < spaces_left; i++)
        {
            rows[row - 1]->add(new Tile(*tile));
        }
        for (int i = 0; i < leftover; i++)
        {
            broken.push_back(new Tile(*tile));
        }
    }
    else
    {
        for (int i = 0; i < amount; i++)
        {
            rows[row - 1]->add(new Tile(*tile));
        }
    }

}
