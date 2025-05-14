#ifndef GAME_H
#define GAME_H

#include <windows.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

extern HANDLE console;
extern COORD CursorPosition;
extern int carPos, score;

void gotoxy(int x, int y);
void setcursor(bool visible, DWORD size);
void menu();
void play();
void drawCar();
void eraseCar();
void drawEnemy(int ind);
void eraseEnemy(int ind);
void genEnemy(int ind);
void resetEnemy(int ind);
int collision();
void updateScore();
void gameover();
void instructions();

#endif

