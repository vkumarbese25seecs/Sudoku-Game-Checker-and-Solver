#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void showBoard(int board[][9]);
bool cheaker(int board[9][9], int x, int y, int value);
void getInput(int &x, int &y, int &value);
void Hint(int board[][9]);
void FullSolution(int board[][9]);
bool isWin(int board[][9]);



int score = 20;
bool running = true;
int x, y, value;
//Function to check if the move is legal

int main() {
	srand(time(0));
	int command;
	

	 int board[9][9] = {
		{0,0,0,1,5,4,0,9,0},
		{3,9,0,0,0,0,8,1,4},
		{7,1,0,0,0,0,0,0,6},
		{4,7,9,3,6,0,0,0,2},
		{8,0,0,0,4,0,6,0,3},
		{0,3,0,5,7,0,0,0,0},
		{0,0,7,0,9,2,0,3,0},
		{1,8,2,0,0,0,7,6,0},
		{0,0,3,7,0,0,2,8,0}
	};
	
	cout << "Initial 9x9 Board of Game is \n";
         showBoard(board);
		 while (running) {
			 //user command 

			 while (score > 0) {
				 cout << "\nWhat you want to do ? \n";
				 cout << "PLAY enter 1\nEXIT enter 2\nSOLUTION enter 3\nNOTE: solution cost 20 energy!\n";
				 cin >> command;

				 if (command == 1) {
					 int a;
					 cout << "If you want any HINT? enter 1 otherwise enter anyother number :  ";
					 cin >> a;
					 if (a == 1) {
						 Hint(board);
						 score -= 10;
					 }
					 else {
						 getInput(x, y, value);
						 if (cheaker(board, x, y, value)) {
							 board[x][y] = value;
							 score += 10;
							 showBoard(board);
							 
						 }
						 else {
							 cout << "The move is not acoording to SUDOKO rules." << endl;
							 score -= 5;
						 }
						 if (isWin(board)){
							 cout << "CONGRATULATIONS!!! You Win the game \n";
							 cout << "Your final score is: " << score << endl;
							 showBoard(board);
						 }
					 }
				 }
				 if (command == 2) {
					 running = false;
					 break;
				 }
				 if (command == 3) {
					 FullSolution(board);
					 score -= 20;
					 cout << "Your final score is: " << score;
					 break;
				 }
			 }
		 }
		
		 if (score == 0 || !running) {
			 cout << "YOU LOST! THE GAME.\n";
		 }
	    return 0;
	} 
	void showBoard(int board[][9]){//Game loop
		
			// Generate output(dispaly a sudoko board)

			for(int i = 0; i < 9; i++) {
				if ((i) % 3 == 0)cout << "---------------------\n";

				for (int j = 0; j < 9; j++) {
					cout << board[i][j] << " ";
					if ((j + 1) % 3 == 0) cout << "|";
				}
				cout << endl;
			
		}
	}
void getInput(int &x, int &y, int &value) {
		//Get user input
		cout << "Enter a Position \nWHICH ROW ? ";
		cin >> x;
		cout << "WHICH COLOUMN ? ";
		cin >> y;
		cout << "Enter the value which you want to enter: ";
		cin >> value;
	}
bool cheaker(int board[9][9], int x, int y, int value) {

	//check to make sure we are on board
	
	if (x!=-1 && x < 0 || x >= 9 || y < 0 || y >= 9) {
		return false;
	}

	//check to make sure value is valid
	if (value < 0 || value>9) {
		return false;
	}

	//check row and coloumn
	for (int i = 0; i < 9; i++) {
		if (i != x && board[i][y] == value) { // Check if 'value' is already in column 'y'
			return false;
		}
	}

	
	for (int j = 0; j < 9; j++) {
		if (j != y && board[x][j] == value) { // Check if 'value' is already in row 'x'
			return false;
		}
	}
	//Subgrid Check:
	int subgrid_x = (x / 3) * 3;
	int subgrid_y = (y / 3) * 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[subgrid_x + i][subgrid_y + j] == value) {
				return false;
			}
		}
	}

	return true;
}

void Hint(int board[][9]) {
	bool z = true;
	while (z) {
		int i = 1 + rand() % 9;
		int j = 1 + rand() % 9;
		
		if (board[i][j] > 0) {
			int value = 1 + rand() % 9;
			if (cheaker(board, i, j, value)) {
				cout << "Enter " << value << " in " << i << "th row and " << j << "th coloumn.";
				z = false;
			}
			else {
				continue;
			}
			
		}
	}
}

void FullSolution(int board[][9]) {
	bool z;
	for (int i = 0; i < 9; i++) {
		
		for (int j = 0; j < 9; j++) {
			z = true;
			while (z) {
				int value = 1 + rand() % 9;
				if (cheaker(board, i, j, value)) {
					board[i][j] = value;
					z = false;
					break;
				}
				else {
					continue;
				}
				
			}
		}
	}
	cout << "Complete solution for the puzzle is:\n";
	showBoard(board);
}

bool isWin(int board[][9]) {
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {		
			if (board[i][j] == 0) {
				return false;

			}
		}
	}
	return true;
}
