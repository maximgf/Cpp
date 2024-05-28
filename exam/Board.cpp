#include "Board.h"


Board::Board()
{
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cells[i][j] = Cell(); // Инициализация каждой ячейки
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
    return typeid(x) == typeid(int) && typeid(y) == typeid(int) && x >= 0 && x < 20 && y >= 0 && y < 20 && cells[x][y].getValue() == ' ';
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
    // Проверка горизонтальной линии
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
    // Проверка вертикальной линии
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
    // Проверка диагоналей
    int b = -1 * ( - 1 * y - 1 * x);
    int curr_x = 0;
    int curr_y = b;
    for (int i = 0; i < 20; ++i) {
        if (x + i >= 0 && y + i < 20 && cells[curr_y+i][curr_x+i].getValue() == player)
        {
            ++count;
            if (count_max < count) {
                count_max = count;
                func = { count_max, 1 };
                aim = { curr_x, curr_y };
            }
        }
    }
    count = 0;
 
    b = -1 * (-1 * y + 1 * x);
    curr_x = 0;
    curr_y = b;
    for (int i = 0; i < 20; ++i) {
        if ((x + i >= 0 && y - i < 20 && cells[curr_y-i][curr_x+i].getValue() == player))
        {
            ++count;
            if (count_max < count) {
                count_max = count;
                func = { count_max, 1 };
                aim = { curr_x, curr_y };
            }
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