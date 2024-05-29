#pragma once
#include "Board.h"
#include<ctime>
class ComputerPlayer
{
public:
	std::pair<int, int> GetMove(const Board& board);
	ComputerPlayer(char player);
	char GetPlayer();
private:
	char player;
};