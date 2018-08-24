#pragma once

void printWelcome();

void printBoard(int board[3][3]);

void turnMsg(int playerTurn);

int takeRow();

int takeCol();

void updateBoard(int board[3][3], int player);

int testForWin(int board[3][3], int player);

int switchTurn(int playerTurn);

void endMsg(int winner);

void play();