#include<iostream>
#include "helper.h"
using namespace std;

// To Do:
// Reduce redundancy between takeRow()
// and takeCol()
// check is using "player" between files
// is okay

// Main application function
int main() {

	// Game board
	int board[3][3] = {};

	// 1 = X
	// 2 = O
	// Player
	int player = 1;

	// 0 = no winner yet
	// 1 = X wins
	// 2 = Y wins
	// 3 = Tie
	// Winner test
	int winner = 0;

	// Welcome user
	printWelcome();
	printBoard(board);

	// winner = testForWin(board, player); // WHY AM I DOING THIS HERE

	// While there is no winner and no tie
	while (winner == 0) {

		// Say whose turn it is
		turnMsg(player);

		// Take new input
		updateBoard(board, player);

		// Show said input
		printBoard(board);

		// Test for winning play
		winner = testForWin(board, player);

		// Switch to next player
		player = switchTurn(player);
	}

	// end message
	endMsg(winner);

	system("pause"); // DELETE
	// exit
	return 0;
}