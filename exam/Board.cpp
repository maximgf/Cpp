#include "Board.h"
#include <iostream>

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
    return x >= 0 && x < 20 && y >= 0 && y < 20 && cells[x][y].getValue() == ' ';
}

void Board::makeMove(int x, int y, char player) {
    cells[x][y].setValue(player);

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
        if (cells[y][i].getValue() == player) {
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
        if (cells[i][y].getValue() == player) {
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
    // Проверка диагоналей
    for (int i = 0; i < 20; ++i) {
        if (x - i >= 0 && y - i >= 0 && cells[x - i][y - i].getValue() == player) {
            ++count;
            if (count_max < count)
            {
                count_max = count;
                func = { count_max,1 };
                aim = { x - i,y - i };
            }
        }
        else {
            count = 0;
        }
    }
    count = 0;
    for (int i = 0; i < 20; ++i) {
        if (x - i >= 0 && y + i < 20 && cells[x - i][y + i].getValue() == player) {
            ++count;
            if (count_max < count)
            {
                count_max = count;
                func = { count_max,-1 };
                aim = { x - i,y + i };
            }
        }
        else {
            count = 0;
        }
    }

    if (count_max > 5)
        count_max = 5;
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