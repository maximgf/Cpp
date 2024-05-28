#pragma once
#include "Cell.h"
#include <vector>

class Board {
public:
    Board();
    void display() const;
    bool isValidMove(int x, int y) const;
    void makeMove(int x, int y, char player);
    std::pair<std::pair<int, int>, std::pair<int, int>> Connectivity(int x, int y, char player) const;

    bool isFull() const;

    std::pair<int, int> getLastMove() const;

private:
    std::pair<int, int> lastMove;
    Cell cells[20][20];
};