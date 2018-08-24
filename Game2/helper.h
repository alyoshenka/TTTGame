#pragma once

void printWelcome();

void printBoard(int board[3][3]);

int turnMsg(int playerTurn);

int takeRow();

int takeCol();

void updateBoard(int board[3][3]);

int testForWin(int board[3][3], int player);

void play();