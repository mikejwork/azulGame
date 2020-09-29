#include "mozaic.h"

Mozaic::Mozaic()
{
    // add the five rows to the mozaic
    for (int i = 0; i < 5; i++)
    {
        rows.push_back(new Row());
    }
}

Mozaic::~Mozaic()
{}

void Mozaic::print_mozaic()
{
    int row_num = 1;
    int blank_space = 4;
    for (int row = 1; row < 6; row++)
    {
        std::cout << row << ":";
        for (int spacing = 0; spacing < blank_space; spacing++)
        {
            std::cout << "  ";
        }

        int empty = row_num - rows[row_num-1]->get_size();
        for (int index = 0; index < empty; index++) 
        {
            std::cout << " .";
        }

        for (int index = 0; index < rows[row_num-1]->get_size(); index++) 
        {
            std::cout << " " << rows[row_num-1]->get_index(index)->get_colour();
        }
        blank_space--;
        row_num++;

        std::cout << " ||" ;
        for (int i = 0; i < 5; i++) 
        {
            if (mozaic[row - 1][i] == nullptr) 
            {
                std::cout << " ." ;
            } 
            else 
            { 
                std::cout << " " << mozaic[row - 1][i]->get_colour();
            }

        }

        std::cout << "\n";
    }

    std::cout << "broken: ";

    for (std::string::size_type i = 0; i < broken.size(); i++) {
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
                    update_points(row_num, i);
                }
            }
            rows[row_num - 1]->clear_row();
        }
        row_num++;
    }
}

void Mozaic::update_points(int row_num, int i)
{
    count(row_num - 1, i);
}

int Mozaic::count(int row_num, int i)
{ //change i to col
    int b = row_num;
    int f = row_num;
    int l = i;
    int r = i;
    int back = 1;
    int top = 2;
    int left = 3;
    int right = 4;

    int countRight = 0;
    int countTop = 0;
    int countLeft = 0;
    int countBot = 0;
    int result = 1;
    bool once;

    once = true;
    while (!returnCheck(row_num, r, right))
    {
        if (once == true) {
            countRight = 1;
            once = false;
        }
        countRight++;
        r++;
    }
    std::cout << "COUNT RIGHT: " << countRight << std::endl;
    once = true;

    while (!returnCheck(row_num, l, left))
    {
        if (once == true) {
            countLeft = 1;
            once = false;
        }
        countLeft++;
        l--;
    }
    std::cout << "COUNT LEFT: " << countLeft << std::endl;
    once = true;

    while (!returnCheck(b, i, back))
    {
        if (once == true) {
            countBot = 1;
            once = false;
        }
        countBot++;
        b++;
    }

    std::cout << "COUNT Bot: " << countBot << std::endl;
    once = true;

    while (!returnCheck(f, i, top))
    {
        if (once == true) {
            countTop = 1;
            once = false;
        }
        countTop++;
        f--;
    }
    std::cout << "COUNT Top: " << countTop << std::endl;


    
    if (!(countRight + countLeft + countTop + countBot) == 0)
    {
        result = countRight + countLeft + countTop + countBot;
    }

    std::cout << "PLAYER SCORE: " << result << std::endl;
    return result;
}

bool Mozaic::returnCheck(int row_num, int i, int a)
{
    bool ans = true;

    if (a == 1)
    {
        //GOES DOWN X
        if (row_num + 1 <= 5)
        {
            if (mozaic[row_num + 1][i] != nullptr)
            {

                ans = false;
            }
        }
    }
    else if (a == 2)
    {
        //Checks UP
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