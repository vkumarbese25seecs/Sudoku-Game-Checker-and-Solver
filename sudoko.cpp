#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void showBoard(int board[][9]);
bool isValid(int board[9][9], int row, int col, int num);
bool cheaker(int board[9][9], int x, int y, int value);
void getInput(int &x, int &y, int &value);
void Hint(int board[][9]);

bool solveSudoku(int board[9][9]);
void FullSolution(int board[][9]);
bool isWin(int board[][9]);
int score = 20;





int main() {
	srand(time(0));
	
	bool running = true;
	int x, y, value;
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
	 cout << "<===WELCOME TO SUDOKO GAME===>" << endl;
	cout << "Initial 9x9 Board of Game is \n";
         showBoard(board);
		 cout << "\nscore = " << score;
		 while (running) {
			 //user command 

			 while (score > 0) {
				 cout << "\nWhat you want to do ? \n";
				 cout << "PLAY enter 1\nEXIT enter 2\nSOLUTION enter 3\nNOTE: solution cost 20 energy!\n";
				 cin >> command;

				 if (command == 1) {
					 int a;
					 cout << "If you want any HINT? enter 1\nNOTE: Hint cost 10 score \notherwise enter anyother number : ";
					 cin >> a;
					 if (a == 1) {
						 if (score >= 10) {
							 Hint(board);
							 score -= 10;
							 cout << "\nscore = " << score;
						 }
						 else {
							 cout << "You dont have enough SCORE for HINT!\n";
						 }
					 }
					 else {
						 getInput(x, y, value);
						 if (cheaker(board, x, y, value)) {
							 board[x][y] = value;
							 score += 5;
							 showBoard(board);
							 cout << "\nscore = " << score;
							 
							 
						 }
						 else {
							 cheaker(board, x, y, value);
							 
							 score -= 5;
							 cout << "\nscore = " << score;
						 }
						 if (isWin(board)){
							 cout << "CONGRATULATIONS!!! You Win the game \n";
							 cout << "Your final score is: " << score << endl;
							 showBoard(board);
							 break;
						 }
					 }
				 }
				 if (command == 2) {
					 running = false;
					 break;
				 }
				 if (command == 3 ) {
					 if (score >= 20) {
						 FullSolution(board);
						 score -= 20;
						 cout << "\nYour final score is: " << score;
						 break;
					 }
					 else {
						 cout << "You dont have enough SCORE for SOLUTION!\n";
					 }
				 }
			 }
		 }
		 if (score <= 0) {
			 cout << "GAME OVER! You ran out of score\n";
		 }
		 else if (!running) {
			 cout << "You exit the game\n";
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
		x--;
		y--;
	}
bool cheaker(int board[9][9], int x, int y, int value) {

	//check to make sure we are on board
	
	if (x < 0 || x >= 9 || y < 0 || y >= 9) {
		cout << "Enter correct position ( 1 to 9) \n";
		return false;
	}
	//do not allow editing fixed cells
	if (board[x][y] != 0) {
		cout << "This is already filled, you cant fill it \n";
		return false;
	}

	bool rule = true;
	//check to make sure value is valid
	if (value <= 0 || value>9) {
		rule = false;
		return false;
	}

	//check row, coloumn and grid
	if (!isValid(board, x, y, value)) {
		rule = false;
		return false;
	}

	if(!rule) {
		cout << "\nThe move is not acoording to SUDOKO rules." << endl;
	}

	return true;
}

void Hint(int board[][9]) {
	bool z = true;
	while (z) {
		int i = rand() % 9;
		int j = rand() % 9;
		
		if (board[i][j] == 0) {
			int value = 1 + rand() % 9;
			if (isValid(board, i, j, value)) {
				cout << "\nHINT => Enter " << value << " in " << i+1 << "th row and " << j+1 << "th coloumn.\n";
				z = false;
			}
			else {
				continue;
			}
			
		}
	}
}
bool isValid(int board[9][9], int row, int col, int num)
{
	for (int x = 0; x < 9; x++) //check coloumns
		if (board[row][x] == num)
			return false;

	for (int x = 0; x < 9; x++) //cheack rows
		if (board[x][col] == num)
			return false;

	int startRow = row - row % 3;
	int startCol = col - col % 3;

	for (int i = 0; i < 3; i++) //cheack grid
		for (int j = 0; j < 3; j++)
			if (board[startRow + i][startCol + j] == num)
				return false;

	return true;
}
 

bool solveSudoku(int board[9][9])
{
	int row , col ;
	bool emptyFound = false;

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){

			if (board[i][j] == 0)
			{
				row = i;
				col = j;
				emptyFound = true;
				break;
			}
		}
		if (emptyFound) break;
	}

	if (!emptyFound)
		return true;

	for (int num = 1; num <= 9; num++){

		if (isValid(board, row,col,num))
		{
			board[row][col] = num;

			if (solveSudoku(board)) {
				return true;
			}

			board[row][col] = 0;
		}
	}

	return false;
}


void FullSolution(int board[][9]) {
	solveSudoku(board);


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
