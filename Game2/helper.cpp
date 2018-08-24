#include <iostream>
#include "helper.h"
using namespace std;

// board size
int SIZE = 3;

// 0 = blank
// 1 = X
// 2 = O
// player marker
// set to 0 later
int playerChar = 1;

int turnCount = 1;

// This function prints a welcome message.
void printWelcome() {
	cout << "This is a Tic Tac Toe Game." << endl;
}

// This function prints the board.
void printBoard(int board[3][3]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
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
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

// This function prints out whose turn it is and then
// switches the turn number
int turnMsg(int playerTurn) {
	if (playerTurn == 1) {
		std::cout << "X's turn." << std::endl;
		// playerTurn = 2; // switches turn
		// playerChar = 1;
	}
	else if (playerTurn == 2) {
		std::cout << "O's Turn." << std::endl;
		// playerTurn = 1; // switches turn
		// playerChar = 2;
	}
	else {
		std::cout << "playerTurn error" << std::endl;
	}
	turnCount++;
	return playerTurn;
}

// IF ELSE HERE	

// This function promts for the row to 
// place a marker
int takeRow() {
	int row = 0;
	std::cout << "What row? ";
	std::cin >> row;
	// input validation
	while (row < 1 || row > SIZE) {
		cout << "Invalid input." << endl;;
		std::cout << "What row? ";
		std::cin >> row;
	}
	return row;
}

// This function promts for the column to 
// place a marker
int takeCol() {
	int col = 0;
	std::cout << "What column? ";
	std::cin >> col;
	// input validation - number
	while (col < 1 || col > SIZE) {
		cout << "Invalid input." << endl;;
		std::cout << "What column? ";
		std::cin >> col;
	}
	return col;
}

// This function updates the game board 
// using the input marker placement
void updateBoard(int board[3][3]) {
	// int c = 0; // switch to char for X and O
	int row = takeRow();
	int col = takeCol();
	/*
	if (playerChar == 1) {
		c = 1;
	}
	else if(playerChar == 2){
		c = 2;
	}
	else {
		cout << "Error" << endl;
	}
	*/

	// while unopen space
	while (board[row-1][col-1] != 0) {
		cout << "This spot has already been played. Pick another." << endl;
		printBoard(board);
		int row = takeRow();
		int col = takeCol();
	}
	board[row-1][col-1] = playerChar;

	// change later
	if (playerChar == 1) {
		playerChar = 2;
	}
	else if (playerChar == 2) {
		playerChar = 1;
	}
	else {
		cout << "Error" << endl;
	}
}


/*
// This function tests to see if a player has won.
// 0 = no winner
// 1 = X wins
// 2 = O wins
// 3 = tie
int testForWin(int board[3][3]) {

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
		{ 1, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 1 } };

	int win8[3][3] = {
		{ 0, 0, 1 },
		{ 0, 1, 0 },
		{ 1, 0, 0 } };
	
	int winningPlays[3][3][8] = {win1[3][3], win2[3][3], 
		win3[3][3], win4[3][3], win5[3][3], win6[3][3],
		win7[3][3], win8[3][3]};

	// for board in winningPlays
	for (int i = 0; i < 8; i++) {
		// checking for X now, modify layer for O
		for (int col = 0; col < SIZE; col++) {
			for (int row = 0; row < SIZE; row++) {
			
			}
		}
	}


	return 0;
}
*/

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

void play() {

	// while someone hasn't won
		// keep playing
}