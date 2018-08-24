#include <iostream>

// int SIZE = 3; 
// int board[3][3];
// int playerTurn = 1; // 1 = X	2 = O

#include<iostream>
#include "helper.h"
using namespace std;

int main() {

	int board[3][3] = {};
	int playerTurn = 1;
	int winner = 0;
	// int turnCount = 1;

	printWelcome();
	printBoard(board);

	winner = testForWin(board, playerTurn);
	while (winner == 0) {
		playerTurn = turnMsg(playerTurn);
		updateBoard(board);
		printBoard(board);
		winner = testForWin(board, playerTurn);
		
		// do in helper (later)
		/*
		if (playerTurn == 1) {
			playerTurn == 2;
		}
		else if(playerTurn == 2) {
			playerTurn == 1;
		}
		else {
			cout << "Error" << endl;
		}
		*/
		
		cout << "Win: " << winner << endl;
	}
	cout << "END" << endl;
	printBoard(board);
	cout << winner << endl;

	switch (winner) {
		case 1:
			cout << "X wins." << endl;
		case 2:
			cout << "O wins." << endl;
		case 3:
			cout << "Tie." << endl;
		default:
			cout << "Error" << endl;
	}


	system("pause");
	return 0;
}