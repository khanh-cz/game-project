#ifndef GAME_H
#define GAME_H

class Game {
private:
    char board[3][3];
    char currentPlayer;

    void drawBoard();
    bool isWin();
    bool isDraw();
    void switchPlayer();
    bool makeMove(int row, int col);

public:
    Game();
    void play();
};

#endif
