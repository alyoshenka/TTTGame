#include <iostream>

int SIZE = 3; 
int board[3][3];
int playerTurn = 1; // 1 = X	2 = O

void printWelcome() {
	std::cout << "This is a Tic Tac Toe Game." << std::endl;
}

void printBoard(int board[3][3]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 1) {
				std::cout << "X";
			}
			else if (board[i][j] == 2) {
				std::cout << "O";
			}
			else {
				std::cout << "+";
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

// This function prints out whose turn it is and then
// switches the turn number
void playerTurnMsg(int playerTurn) {
	if (playerTurn == 1) {
		std::cout << "X's turn." << std::endl;
		playerTurn = 2; // switches turn
	}
	else if (playerTurn == 2) {
		std::cout << "O's Turn." << std::endl;
		playerTurn = 1; // switches turn
	}
	else {
		std::cout << "playerTurn error" << std::endl;
	}
}

int takeRow() {
	int row = 0;
	std::cout << "What row? ";
	std::cin >> row;
	return row;
}

int takeCol() {
	int col = 0;
	std::cout << "What column? ";
	std::cin >> col;
	return col;
}

void updateBoard() {
	int row = takeRow();
	int col = takeCol();
}

int main() {

	printWelcome();
	printBoard(board);
	playerTurnMsg(playerTurn);
	printBoard(board);
	updateBoard();

	system("pause");
	return 0;
}