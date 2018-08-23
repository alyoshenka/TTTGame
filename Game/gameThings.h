#pragma once

void printBoard(int arr[3][3]);

void newTurnMsg(bool isXTurn);

int testForWinner(int arr[3][3]);

int takeRow();

int takeCol();

void changeBoard(int arr[3][3]);

void winMsg(int winner);