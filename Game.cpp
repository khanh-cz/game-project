#include "Game.h"
#include <iostream>
#include <iomanip> // For formatting output

void Game::drawBoard() {
    std::cout << "\n";
    std::cout << "   0   1   2\n";  
    std::cout << "  -------------\n";  // Separator line
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " | ";  // Row number
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];  // Print each cell
            if (j < 2) std::cout << " | ";  // Separator between cells
        }
        std::cout << " |\n";  // End of the row
        if (i < 2) std::cout << "  -------------\n";  // Separator between rows
    }
    std::cout << "  -------------\n";  // Bottom separator line
    std::cout << "\n";
}

// Constructor to initialize the game
Game::Game() {
    currentPlayer = 'X';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

// Function to make a move
bool Game::makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

// Function to check if there is a winner
bool Game::isWin() {
    for (int i = 0; i < 3; ++i) {
        // Check rows
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        // Check columns
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

// Function to check if the game is a draw
bool Game::isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// Function to switch to the next player
void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Main function to play the game
void Game::play() {
    int row, col;
    while (true) {
        drawBoard();  // Draw the game board
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

        switchPlayer();  // Switch to the other player
    }
}
