#include "Game.h"
#include <iostream>
#include <iomanip> 

void Game::drawBoard() {
    std::cout << "\n";
    std::cout << "   0   1   2\n";  
    std::cout << "  -------------\n";  
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " | "; 
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];  
            if (j < 2) std::cout << " | "; 
        }
        std::cout << " |\n";  
        if (i < 2) std::cout << "  -------------\n";  
    }
    std::cout << "  -------------\n";  
    std::cout << "\n";
}

Game::Game() {
    currentPlayer = 'X';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

bool Game::makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool Game::isWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

bool Game::isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void Game::play() {
    int row, col;
    while (true) {
        drawBoard();  
        std::cout << "Player " << currentPlayer << "'s turn. Enter position (row column): ";
        std::cin >> row >> col;

        if (!makeMove(row, col)) {
            std::cout << "\n[ERROR] Invalid position or already chosen, please try again.\n";
            continue;
        }

        if (isWin()) {
            drawBoard();
            std::cout << "\nCongratulations! Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isDraw()) {
            drawBoard();
            std::cout << "\nIt's a draw!\n";
            break;
        }

        switchPlayer();  
    }
}
