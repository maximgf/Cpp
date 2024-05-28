 #include "Game.h"
#include "ComputerPlayer.h"
#include <fstream>
#include <vector>


void Game::play() {
    char player = 'X';
    ComputerPlayer computer;
    while (true) {
        if (player == 'X') {
            int x, y;
            std::cout << "Enter your move (x y): ";
            std::cin >> x >> y;

            if (!board.isValidMove(x, y)) {
                std::cout << "Invalid move. Try again." << std::endl;
                continue;
            }
            system("cls");
            std::cout << "Player step:\n";
            board.makeMove(x, y, player);
            board.display();
            if (board.Connectivity(x, y, player).first.first == 5) {
                std::cout << "You win!" << std::endl;
                break;
            }
        }
        else {
            system("cls");
            std::cout << "Computer step:\n";
            auto move = computer.GetMove(board, player);
            board.makeMove(move.first, move.second, player);
            board.display();
            if (board.Connectivity(move.first, move.second, player).first.first == 5) {
                std::cout << "Computer wins!" << std::endl;
                break;
            }
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}

