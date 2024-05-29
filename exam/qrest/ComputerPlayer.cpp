#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(char player)
{
	this->player = player;
}

char ComputerPlayer::GetPlayer()
{
	return player;
}


std::pair<int, int> ComputerPlayer::GetMove(const Board& board)

{
	return board.Hint(board, player, board.getLastMove());
}

