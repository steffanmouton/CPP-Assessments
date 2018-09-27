# Tic Tac Toe Documentation

Steffan Mouton

s188045

IntroCPP Assessment

## Requirements Documentation

- Description of Problem
  - Name: Tic Tac Toe
  - Problem Statement: Create a program that allows two players on the same computer to play a game of Tic Tac Toe
  - Problem Specification: Two players alternate placing tokens on a 3 by 3 grid. The first player to get three of their respective tokens in a row wins. Player cannot place tokens on occupied sections of the grid. A player cannot place more than one token on their turn. A victory condition is met when a player has placed three of their tokens in a row horizontally, vertically, or diagonally. If all sections of the grid are filled and no player has met a victory condition the game ends in a draw.
    Program will finish when app is forced to quit, a player has won, or the draw condition is met.
    Must use variables, conditionals, loops, and arrays.

- Input Information
  - N/A
- Output Information
  - Computer prints current state of board and the current instructions on how to play. Will also print the victor when there is a winner.

- User Interface Information
  - Description: All interface occurs in the console. The first player is given instructions.
    First Player is ‘X’ and inputs a value 0-2 to determine the row and then another value 0-2 to determine the column. Their token is placed in the chosen location. Instructions are then printed for Second Player ‘O’, along with the current state of the board.
    Final output is of the winner’s token.

## Design Documentation

- System Architecture Description:
    All functionality occurs in the main function.
- Information about the objects
- Class Information
  - N/A

## Implementation Documentation

- Program Code

```C++
#include <iostream>
#include <time.h>

int main()
{
	// Initialize turn counter and grid
	char token = 'X';
	int row;
	int column;
	bool victory = false;
	int turn = 0;
	

	char play[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };

	//Game runs while there is no winner or until a draw
	do 
	{
			//turn counter
			
		
			//Player instructions and input
			std::cout << "Player " << token << " choose where to place by entering two values. The first (0-2) determines the row, the second (0-2) determines the column.";
			std::cin >> row >> column;

			if (play[row][column] == ' ')
			{
				play[row][column] = token;
				turn++;
			}
			else
			{
				std::cout << "That is not a valid location. Please choose another!\n";
				continue;
			}

			//Display Board
			for (int i = 0; i<3; i++)
			{
				if (i<2)
				{
					std::cout << play[0][i] << "|";
				}
				if (i == 2)
				{
					std::cout << play[0][i] << std::endl;
				}
			}
			std::cout << "------\n";

			for (int i = 0; i<3; i++)
			{
				if (i<2)
				{
					std::cout << play[1][i] << "|";
				}
				if (i == 2)
				{
					std::cout << play[1][i] << std::endl;
				}
			}
			std::cout << "------\n";

			for (int i = 0; i<3; i++)
			{
				if (i<2)
				{
					std::cout << play[2][i] << "|";
				}
				if (i == 2)
				{
					std::cout << play[2][i] << std::endl;
				}
			}

			//Check for Victory
			//Horizontal Victory
			for (int i = 0; i<3; i++)
			{
				if (play[i][0] != ' ')
				{
					if (play[i][0] == play[i][1] && play[i][0] == play[i][2])
					{
						victory = true;
						break;
					}
					else
					{
						continue;
					}
				}

			}
			//Vertical Victory
			for (int i = 0; i < 3; i++)
			{
				if (play[0][i] != ' ')
				{
					if (play[0][i] == play[1][i] && play[0][i] == play[2][i])
					{
						victory = true;
						break;
					}
					else
					{
						continue;
					}
				}
			}

			//Diagonal Victory

			if (play[0][0] == play[1][1] && play[0][0] == play[2][2])
			{
				if (play[0][0] != ' ')
				{
					victory = true;
					break;
				}
			}
			if (play[2][0] == play[1][1] && play[2][0] == play[0][2])
			{
				if (play[2][0] != ' ')
				{
					victory = true;
					break;
				}
			}
		
			//Check for tie
			if (victory == false && turn > 8)
			{
				std::cout << "Tie game";
				break;
			}

			//change Token
			if (victory == false)
			{
				token = (token == 'X') ? 'O' : 'X';
			}
	}
	while (victory == false);

	std::cout << "The winner is: " << token << std::endl;
	system("pause");

}
```