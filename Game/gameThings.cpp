#include "gameThings.h"
#include <iostream>

// TTT board
// 0 = open
// 1 = X
// 2 = O
// prints ttt board in current state
void printBoard(int arr[3][3]) {
	int row = 0;
	int col = 0;
	for (col = 0; col <= 2; col++) {
		for (row = 0; row <= 2; row++) {
			std::cout << arr[row][col];
		}
		std::cout << std::endl;
	}
}

// prints turn number and whose turn it is
void newTurnMsg(bool isXTurn) {
	if (isXTurn) {
		std::cout << "X's Turn." << std::endl;
	}
	else {
		std::cout << "Y's Turn." << std::endl;
	}
	isXTurn = false;
}

// tests is someone has made a winning play
// return 0 for none
// 1 for X
// 2 for O
int testForWinner(int arr[3][3]) {
	return 0;
}

// takes row input
int takeRow() {
	int row = 0; 
	std::cout << "Where would you like to play?" << std::endl;
	std::cout << "Enter row: ";
	std::cin >> row;
	return row;
}

// takes column input
int takeCol() {
	int col = 0;
	std::cout << "Enter col: ";
	std::cin >> col;
	return col;
}

// changes the board after taking move input
void changeBoard(int board[3][3]) {
	int row = takeRow();
	int col = takeCol();
	board[col-1][row-1] = 1; // backwards!
	// std::cout << board[row - 1][col - 1] << std::endl; // test
}

// checks if board matches a winning board layout
bool checkForWin(int board[3][3]) {
	
	// winning moves
	int win1[3][3] = {
		{ 1, 1, 1 },
		{ 0, 0, 0 },
		{ 0, 0, 0 } };

	int win2[3][3] = {
		{ 0, 0, 0 },
		{ 1, 1, 1 },
		{ 0, 0, 0 } };

	int win3[3][3] = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 1, 1, 1 } };

	int win4[3][3] = {
		{ 1, 0, 0 },
		{ 1, 0, 0 },
		{ 1, 0, 0 } };

	int win5[3][3] = {
		{ 0, 1, 0 },
		{ 0, 1, 0 },
		{ 0, 1, 0 } };

	int win6[3][3] = {
		{ 0, 0, 1 },
		{ 0, 0, 1 },
		{ 0, 0, 1 } };

	int win7[3][3] = {
		{ 1, 0, 0  },
		{ 0, 1, 0 },
		{ 0, 0, 1 } };

	int win8[3][3] = {
		{ 0, 0, 1 },
		{ 0, 1, 0 },
		{ 1, 0, 0 } };

	// int winConditions[3][3][8] = { win1, win2, win3,
	// 	win4, win5, win6, win7, win8 };

	// there's a better way to do this
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != win1[i][j]) {
				return false;
			}
		}
	}

	return true;
}

// displays who won
void winMsg(int winner) {
	if (winner == 1) {
		std::cout << "X won." << std::endl;
	}
	else if (winner == 0) {
		std::cout << "O won." << std::endl;
	}
	else {
		std::cout << "Error" << std::endl;
	}
}