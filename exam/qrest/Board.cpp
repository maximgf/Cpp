#include "Board.h"


Board::Board()
{
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cells[i][j] = Cell();  
        }

    }
}


void Board::display() const {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            std::cout << cells[i][j].getValue();
        }
        std::cout << std::endl;
    }
}

bool Board::isValidMove(int x, int y) const {
    return (typeid(x) == typeid(int)) && (typeid(y) == typeid(int)) && x >= 0 && x < 20 && y >= 0 && y < 20 && cells[y][x].getValue() == ' ';
}

void Board::makeMove(int x, int y, char player) {
    cells[y][x].setValue(player);

    lastMove = std::make_pair(x, y);

}

std::pair<std::pair<int, int>, std::pair<int, int>> Board::Connectivity(int x, int y, char player) const {
    int count = 0;
    int count_max = 0;
    int k;
    std::pair<int, int> func;
    std::pair<int, int> aim;
    std::pair<std::pair<int, int>, std::pair<int, int>> result;
 
    for (int i = 0; i < 20; ++i) {
        if (cells[y][i].getValue() == player)
        {
            ++count;
            if (count_max < count)
            {
                count_max = count;
                func = { count_max,0 };
                aim = { i,y };
            }
        }
        else {
            count = 0;
        }
    }
    count = 0;
 
    for (int i = 0; i < 20; ++i) {
        if (cells[i][x].getValue() == player) {
            ++count;
            if (count_max < count)
            {
                count_max = count;
                func = { count_max,0 };
                aim = { x,i };
            }
        }
        else {
            count = 0;
        }
    }
    count = 0;
    //-y = kx+b, b = -y -kx, k = 1
    int b = -1 * (-1 * y - 1 * x);
    int curr_x = 0 - 1;
    int curr_y = b + 1;
    for (int i = 0; i < 20; i++)
    {
        curr_y -= 1;
        curr_x += 1;
        if ((curr_x < 20) && (curr_y < 20) && (curr_y >=0) && (cells[curr_y][curr_x].getValue() == player))
        {
            ++count;
            if (count_max < count) 
            {
                count_max = count;
                func = { count_max, 1 };
                aim = { curr_x, curr_y };
            }
        }
        else {
            count = 0;
        }
    }
    count = 0;
    //-y = kx+b, b = -y -kx, k = -1
    b = -1 * (-1 * y + 1 * x);
    curr_x = 0 - 1;
    curr_y = b - 1;
    for (int i = 0; i < 20; i++)
    {
        curr_y += 1;
        curr_x += 1;
        if ((curr_x < 20) && (curr_y < 20) && (curr_y >= 0) && (cells[curr_y][curr_x].getValue() == player))
        {
            ++count;
            if (count_max < count)
            {
                count_max = count;
                func = { count_max, 1 };
                aim = { curr_x, curr_y };
            }
        }
        else {
            count = 0;
        }
    }

    if (count_max > 5)
    {
        count_max = 5;
        func.first = count_max;
    }

    result = { func, aim };

    return result;
}

bool Board::isFull() const {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (cells[i][j].getValue() == ' ') {
                return false;
            }
        }
    }
    return true;
}

std::pair<int, int> Board::getLastMove() const {
    return lastMove;
}

std::pair<int, int> Board::Hint(const Board& board,char player, std::pair<int,int> step_enemy) const
{
    while (true)
    {
        srand(time(nullptr));
        int x = rand() % 20;
        int y = rand() % 20;
        if (isValidMove(x, y))
        {
            return { x,y };

        }
    }
}
/*Board b = board;
char enemy;
enemy = (computer == 'O') ? 'X' : 'O';
int trigger = b.Connectivity(b.getLastMove().first, b.getLastMove().second, enemy).first.first;
if (trigger > 2)
{
    return CalcMove(b, enemy, b.getLastMove());
}
else
    current_step = CalcMove(b, computer, current_step);
return current_step;*/


/*std::pair<int, int> ComputerPlayer::CalcMove(const Board& board, char Symbol, std::pair<int, int> last_step)
{
    Board b = board;

    std::pair<std::pair<int, int>, std::pair<int, int>> base = b.Connectivity(last_step.first, last_step.second, Symbol);

    int connect = base.first.first;

    int k = base.first.second;

    std::pair<int, int> last_elem = base.second;

    int x, y;


    if (k == 90)
    {
        x = last_elem.first;
        y = last_elem.second + 1;
        if (b.isValidMove(x, y))
        {
            return { x,y };
        }
        else
        {
            return{ x,y - (connect + 1) };
        }
    }

    if (k == 0)
    {
        x = last_elem.first + 1;
        y = last_elem.second;
        if (b.isValidMove(x, y))
        {
            return { x,y };
        }
        else
        {
            return{ x - (connect + 1),y };
        }
    }

    if (k == 1)
    {
        x = last_elem.first - 1;
        y = last_elem.second - 1;
        if (b.isValidMove(x, y))
        {
            return { x,y };
        }
        else
        {
            return{ x + (connect + 1),y + (connect + 1) };
        }
    }

    if (k == -1)
    {
        x = last_elem.first - 1;
        y = last_elem.second + 1;
        if (b.isValidMove(x, y))
        {
            return { x,y };
        }
        else
        {
            return{ x + (connect + 1),y - (connect + 1) };
        }
    }



}*/