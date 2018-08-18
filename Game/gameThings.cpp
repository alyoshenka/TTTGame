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
void newTurnMsg(int turnNumber) {

}

// tests is someone has made a winning play
// return 0 for none
// 1 for X
// 2 for O
int testForWinner(int arr[3][3]) {
	return 0;
}