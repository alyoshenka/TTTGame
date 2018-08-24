#include <iostream>
#include "helper.h"
using namespace std;

// board size
int SIZE = 3;

// Turn number
int turnCount = 1;

// This function prints a welcome message.
void printWelcome() {
	std::cout << std::endl;
	cout << "This is a Tic Tac Toe Game." << endl;
}

// This function prints the board.
void printBoard(int board[3][3]) {
	std::cout << std::endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			/*
			if (board[i][j] == 1) {
				std::cout << "X";
			}
			else if (board[i][j] == 2) {
				std::cout << "O";
			}
			else if(board[i][j] == 0){
				std::cout << "+";
			}
			else {
				cout << "Error" << endl;
			}
			*/

			switch (board[i][j]) {
				// 1 = X
				case 1:
					std::cout << "X";
					break;
				// 2 = O
				case 2:
					std::cout << "O";
					break;
				// 0 = blank
				case 0:
					std::cout << "+";
					break;
				// This should never happen
				default:
					std::cout << "Error";
			}
			// spacer
			std::cout << "  ";
		}
		// spacer
		std::cout << std::endl;
		// new line
		std::cout << std::endl;
	}
}

// This function prints out whose turn it is and then
// switches the turn number
void turnMsg(int player) {
	std::cout << std::endl;
	if (player == 1) {
		std::cout << "X's turn." << std::endl;
		// playerTurn = 2; // switches turn
		// playerChar = 1;
	}
	else if (player == 2) {
		std::cout << "O's Turn." << std::endl;
		// playerTurn = 1; // switches turn
		// playerChar = 2;
	}
	else {
		std::cout << "Error" << std::endl;
	}
	// Update turn count
	turnCount++;
}

// IF ELSE HERE	

// This function promts for the row to 
// place a marker
int takeRow() {
	std::cout << std::endl;
	int row = 0;
	std::cout << "In what row would you like to play? ";
	std::cin >> row;
	// input validation
	while (row < 1 || row > SIZE) {
		std::cout << std::endl;
		cout << "Invalid input." << endl;;
		std::cout << std::endl;
		std::cout << "In what row would you like to play? ";
		std::cin >> row;
	}
	return row;
}

// This function promts for the column to 
// place a marker
int takeCol() {
	std::cout << std::endl;
	int col = 0;
	std::cout << "In what column would you like to play? ";
	std::cin >> col;
	// input validation - number
	while (col < 1 || col > SIZE) {
		std::cout << std::endl;
		cout << "Invalid input." << endl;;
		std::cout << std::endl;
		std::cout << "In what row would you like to play? ";
		std::cin >> col;
	}
	return col;
}

// This function updates the game board 
// using the input marker placement
void updateBoard(int board[3][3], int player) {
	// int c = 0; // switch to char for X and O
	int row = takeRow() - 1; // index = 0
	int col = takeCol() - 1;

	// while unopen space
	while (board[row][col] != 0) {
		cout << "This spot has already been played. Pick another." << endl;
		turnMsg(player);
		printBoard(board);
		int row = takeRow();
		int col = takeCol();
	}
	board[row][col] = player;
}

// This function tests for a winning play.
int testForWin(int board[3][3], int player) {

	// you can't win until 5 moves have been played
	if (turnCount < 5) {
		return 0;
	}

	// if all moves have been taken
	// tie
	if (turnCount == 9) {
		return 3;
	}

	// check vertical 
	for (int i = 0; i < SIZE; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]
				&& board[i][0] == player) {
			return player;
		}
	}

	// check horizontal
	for (int i = 0; i < SIZE; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]
				&& board[0][i] == player) {
			return player;
		}
	}

	// check diagonal
	// if in center
	if (board[1][1] == player) {
			// top left to bottom right
		if ((board[0][0] == player && board[2][2] == player) ||
			// top right to bottom left
			(board[0][2] == player && board[2][0] == player)) {
			return player;
		}
	}

	// no win, no tie
	return 0;
}

// This function switches the turn counter
int switchTurn(int playerTurn) {
	if (playerTurn == 1) {
		return 2;
	}
	if (playerTurn == 2) {
		return 1;
	}
}

void endMsg(int winner) {

	// Say that game has ended
	std::cout << std::endl;
	cout << "GAME OVER" << endl;
	std::cout << std::endl;

	// List winner
	switch (winner) {
	case 1:
		cout << "X wins." << endl;
		break;
	case 2:
		cout << "O wins." << endl;
		break;
	case 3:
		cout << "Tie." << endl;
		break;
	default:
		cout << "Error" << endl;
	}
	std::cout << std::endl;
}

void play() {

	// while someone hasn't won
		// keep playing
}