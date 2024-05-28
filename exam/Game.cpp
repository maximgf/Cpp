#include "Game.h"
#include <fstream>
 


void Game::play() {
    char player = 'X';
    ComputerPlayer computer;

    while (true) {
        if (board.isFull())
        {
            std::cout << "DRAW";
            SaveHistory();
            break;
        }
        if (player == 'X') {
            int x, y;
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
            auto move = computer.GetMove(board, player);
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

    // Открываем файл в режиме дозаписи, если файл не существует, он будет создан
    file.open("history.txt", std::ios::app);

    if (file.is_open()) {
        file << "GAME" << std::endl;
        for (int i = 0; i < history.size();i++) 
        {
            std::string play = "O: ";
            if (i % 2 == 0)
            {
                play = "X: ";
            }
            std::cout << play << history[i].first << " " << history[i].second << std::endl;
            file << play << history[i].first<< " " << history[i].second << std::endl; // Записываем каждый элемент вектора в файл
        }
        file.close(); // Закрываем файл после записи
        std::cout << "DATA is history.txt" << std::endl;
    }
    else {
        std::cout << "Data is none" << std::endl;
    }


}

