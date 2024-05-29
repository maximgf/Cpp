#include "Game.h"
#include <fstream>



void Game::play() {
    char player = 'X';
    ComputerPlayer computer('O');

    while (true) {
        if (board.isFull())
        {
            std::cout << "DRAW";
            SaveHistory();
            break;
        }
        if (player == 'X') {
            int x, y;
            std::cout <<"Hint* X: " << board.Hint(board, player, board.getLastMove()).first << " Y: " << board.Hint(board, player, board.getLastMove()).second<<std::endl;
            std::cout << "Enter your move <x y>: ";
            std::cin >> x >> y;

            if (!board.isValidMove(x, y)) {
                std::cout << "Invalid move. Try again." << std::endl;
                continue;
            }
            system("cls");
            std::cout << "Player step:\n";
            board.makeMove(x, y, player);
            history.push_back({ x,y });
            board.display();
            if (board.Connectivity(x, y, player).first.first == 5) {
                std::cout << "You win!" << std::endl;
                SaveHistory();
                break;
            }
        }
        else {
            system("cls");
            std::cout << "Computer step:\n";
            auto move = computer.GetMove(board);
            board.makeMove(move.first, move.second, player);
            history.push_back(move);
            board.display();
            if (board.Connectivity(move.first, move.second, player).first.first == 5) {
                std::cout << "Computer wins!" << std::endl;
                SaveHistory();
                break;
            }
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}

void Game::SaveHistory()
{
    std::ofstream file;

 
    file.open("history.txt", std::ios::app);

    if (file.is_open()) {
        file << "GAME" << std::endl;
        for (int i = 0; i < history.size(); i++)
        {
            std::string play = "O: ";
            if (i % 2 == 0)
            {
                play = "X: ";
            }
            std::cout << play << history[i].first << " " << history[i].second << std::endl;
            file << play << history[i].first << " " << history[i].second << std::endl;  
        }
        file.close();  
        std::cout << "DATA is history.txt" << std::endl;
    }
    else {
        std::cout << "Data is none" << std::endl;
    }


}

void Game::GameDemonstration()
{
    ComputerPlayer computer_X('X');
    ComputerPlayer computer_O('O');
    char player = 'X';
    std::pair<int,int> move;
    while (true) 
    {
        if (board.isFull())
        {
            std::cout << "DRAW";
            SaveHistory();
            break;
        }
        if (player == 'X')
        {
            std::cout << "Computer_X step:\n";
            move = computer_X.GetMove(board);
            board.makeMove(move.first, move.second, player);
        }
        else
        {
            std::cout << "Computer_O step:\n";
            move = computer_O.GetMove(board);
            board.makeMove(move.first, move.second, player);
        }
           
            history.push_back(move);
            system("cls");
            board.display();
            if (board.Connectivity(move.first, move.second, player).first.first == 5) {
                std::cout << "Computer " << player << " wins!" << std::endl;
                SaveHistory();
                break;
            }
            player = (player == 'X') ? 'O' : 'X';
            //Sleep(1000);
    }
        
        
}


