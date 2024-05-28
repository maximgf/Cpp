#pragma once
#include "Board.h"
#include <utility>

class ComputerPlayer
{
public:
	std::pair<int, int> GetMove(const Board& board, char computer);
	ComputerPlayer();
private:
	std::pair<int, int> current_step;
	std::pair<int, int> CalcMove(const Board& board, char Symbol, std::pair<int, int> last_step);
	
};