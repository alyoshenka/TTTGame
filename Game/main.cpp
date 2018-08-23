#include <iostream>
#include "gameThings.h"

int main() {

	// variables
	// ttt game board
	// = {0}; ?
	// [rows] [columns]
	int board[3][3] = 
	{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	/*
	Steps For Game
		Display welcome
		show board
		show turn
		prompt turn
		input move
		update board
		update player's turn
		show board
		show turn
		prompt turn

		check for wins
		display win message
		exit	
	*/


	// turn number (1-9)
	int turnNum = 1;

	// welcome message
	std::cout << "Welcome to Tic-Tac-Toe." << std::endl;
	std::cout << "X goes first." << std::endl;
	// printBoard(board);
	// newTurnMsg(turnNum);
	changeBoard(board);
	printBoard(board);

	winMsg(1);
	system("pause");
	return 0;
}