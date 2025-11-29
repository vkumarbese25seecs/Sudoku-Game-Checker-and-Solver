# FoCP-Assignment
## Sudoko Game
### Team 
|Name |CMS ID |Role|
|--- |--- |--- |
|Vishal Kumar |544454 |1. Logic designer 2. Programmer |
|Mohsin Abbas |540316 |1. Programmer 2. Git Manager |

## Overview
The goal of this project was to create a fully functional, console-based implementation of the classic 9x9 Sudoku puzzle. The
program must be capable of generating a solvable puzzle, managing player input, providing real-time validation of moves against Sudoku rules, and maintaining a score based on performance. This project serves as a real-world relevant application of data structures (2D arrays) and recursive algorithms (backtracking).

## Execution Instruction
This programm starts with a welcome messege and a 9x9 board with initial score equal to 20,it then asks the user to for input
to start, it says what you want to do  
1. Play  enter 1  
2. Solution enter 2
3. Exit enter 3

If you enter 3 game will exit, if you enter 2 full solution will be shown, but the solution costs 20 score so you should have
enough score. if you enter 1 again the programm will ask if you want any hint enter 1 else enter any enter, if you enter 1
the hint will be shown but hint also costs 10 score so you must have enough score, beside that if you enter any other number
the progrmm will ask for the input the Row, the Coloumn, the Value you want to enter, then the value will be checked if it
is valid accoding to gthe rules then it will be accepted and again same process wil start , the right input will increase the 
score by 5 , but if the input is wrong the score will be decreadsed by 5. The game ends if either you win or your score becomes zero.



