#include "ComputerPlayer.h"
#include <algorithm>

ComputerPlayer::ComputerPlayer()
{

}

std::pair<int, int> ComputerPlayer::CalcMove(const Board& board, char Symbol, std::pair<int, int> last_step)
{
	return std::pair<int, int>();
}

std::pair<int, int> ComputerPlayer::GetMove(const Board& board, char computer)

{
	srand(time(nullptr));
	int x = rand();
	int y = rand();
	return { x % 20,y % 20 };




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
}

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