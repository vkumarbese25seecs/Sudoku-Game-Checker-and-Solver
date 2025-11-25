#include<iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
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
bool start;




int main() { // main (brain)
	srand(time(0));
	auto startTime = chrono::steady_clock::now();
	bool running = true;
	int x, y, value;
	int command;
	

	 int board[9][9] = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0}
	};
	 cout << "=====================================\n";
	 cout <<YELLOW<< "        Welcome to Sudoku Game       \n"<<RESET;
	 cout << "=====================================\n";
	 cout << CYAN <<"Initial 9x9 Board of Game is \n"<<RESET;
           
         
          solveSudoku(board); //we solve it 1st because we want random board every time
          for(int I=0; I<40; I++){
             board[rand()%9][rand()%9] = 0;
             }
         showBoard(board);
		 cout << BLUE << "\nscore = " << score << RESET;
		 while (running && score > 0) {
			 //user command 

		
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
							 cout << BLUE << "\nscore = " << score << RESET;
						 }
						 else {
							 cout << RED << "You dont have enough SCORE for HINT!" << RESET << endl;
						 }

					 }
					 else {
						 getInput(x, y, value);
						 if (cheaker(board, x, y, value)) {
							 board[x][y] = value;
							 score += 5;
							 showBoard(board);
							 cout << BLUE << "\nscore = " << score << RESET;
							 
							 
						 }
						 else {
							
							 
							 score -= 5;
							 cout << BLUE << "\nscore = " << score << RESET;
						 }
						 if (isWin(board)){
							 cout <<GREEN<< "\nCONGRATULATIONS!!! You Win the game 🎉🥳 \n"<<RESET;

							 auto endTime = chrono::steady_clock::now(); //COUT TIME
							 auto totalTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();

							 cout <<YELLOW<< "You completed the game in: " << totalTime << " seconds\n"<<RESET;

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
						 cout << BLUE << "\nscore = " << score << RESET;
						 break;
					 }
					 else {
						 cout << RED<<"You dont have enough SCORE for SOLUTION!"<<RESET<<endl;
					 }
				 }
			 
		 }
		 if (score <= 0) {
			 auto endTime = chrono::steady_clock::now();
			 auto totalTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
			 cout <<RED<< "\nGAME OVER! You ran out of score\n"<<RESET;
			 cout << YELLOW << "Time played: " << totalTime << " seconds\n" << RESET;
		 }
		 if (!running) {
			 auto endTime = chrono::steady_clock::now();
			 auto totalTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();

			 cout <<RED<< "You exit the game\n"<<RESET;
			 cout <<YELLOW<< "Time played: " << totalTime << " seconds\n"<<RESET;
		 }

	    return 0;
	} 
void showBoard(int board[][9]) { //show complete board
    for (int i = 0; i < 9; i++) {

        if (i % 3 == 0) 
            cout << "---------------------" << RESET << endl;

        for (int j = 0; j < 9; j++) {

            if (board[i][j] == 0)
                cout << RED << board[i][j] << " " << RESET;       // empty = red
            else
                cout << GREEN << board[i][j] << " " << RESET;     // filled = green

            if ((j + 1) % 3 == 0)
                cout  << "|" << RESET;
        }
        cout << endl;
    }
}
void getInput(int &x, int &y, int &value) { // for user input
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
bool cheaker(int board[9][9], int x, int y, int value) { // it will cheacks if user enter somthing not valid like rows > 9 or enter number <1 0r >9 and also cheacks rules of sudoko

	//check to make sure we are on board
	
	if (x < 0 || x >= 9 || y < 0 || y >= 9) {
		cout <<RED<< "Enter correct position ( 1 to 9) "<<RESET<<endl;
		return false;
	}
	//do not allow editing fixed cells
	if (board[x][y] != 0) {
		cout <<RED<< "This is already filled, you cant fill it "<<RESET<<endl;
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
		cout << RED << "Invalid move! The move is not acoording to SUDOKO rules." <<RESET<< endl;
	}

	return true;
}

void Hint(int board[][9]) { // give random hints
	bool z = true;
	while (z) {
		int i = rand() % 9;
		int j = rand() % 9;
		
		if (board[i][j] == 0) {
			int value = 1 + rand() % 9;
			if (isValid(board, i, j, value)) {
				cout <<BLUE<< "\nHINT => Enter " << value << " in " << i+1 << "th row and " << j+1 << "th coloumn."<<RESET<<endl;
				z = false;
			}
			else {
				continue;
			}
			
		}
	}
}
bool isValid(int board[9][9], int row, int col, int num) //cheak rules of sudoko
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
 

bool solveSudoku(int board[9][9]) //solve sudoko 
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


void FullSolution(int board[][9]) { //print full solution
	solveSudoku(board);


	
	if(solveSudoku) {
		cout << "\nComplete solution for the puzzle is:\n";
		showBoard(board); 
	}
}

bool isWin(int board[][9]) { //will cheak if every grid is filled with correct number 
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {		
			if (board[i][j] == 0) {
				return false;

			}
		}
	}
	return true;
}
