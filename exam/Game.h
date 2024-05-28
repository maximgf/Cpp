#pragma once
#include "Board.h"
#include "ComputerPlayer.h"
#include<vector>
class Game {
private:
    Board board;
    std::vector <std::pair<int,int>> history;
public:
    void play();
    void SaveHistory();
};