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
	
	// turn number (1-9)
	int turnNum = 0;

	// welcome message
	std::cout << "Welcome to Tic-Tac-Toe." << std::endl;
	std::cout << "X goes first." << std::endl;

	printBoard(board);

	system("pause");
	return 0;
}