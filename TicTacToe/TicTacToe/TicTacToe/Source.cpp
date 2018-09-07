#include <iostream>
#include <time.h>


int main()
{
	// Initialize turn counter and grid
	int turn = 1;
	int turnCount = 0;
	int row;
	int column;
	char victory = ' ';
	int xCount = 0;
	int oCount = 0;

	char play[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };

	//Game runs while there is no winner or until a draw
	while (victory != 'X' || victory != 'O' || turnCount != 9)
	{
		if (turn == 1)
		{
			//Player 1 instructions and input
			std::cout << "Player 1, you are 'X', choose where to place by entering two values. The first (0-2) determines the row, the second (0-2) determines the column.";
			std::cin >> row >> column;

			if (play[row][column] == ' ')
			{
				play[row][column] = 'X';
				turn++;
				turnCount++;
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
				for (int j = 0; j<3; j++)
				{
					if (play[i][j] == 'X')
					{
						xCount++;
					}
				}

				if (xCount == 3)
				{
					victory = 'X';
					break;
				}
				else
				{
					xCount = 0;
				}


			}
			//Vertical Victory
			for (int i = 0; i<3; i++)
			{
				for (int j = 0; j<3; j++)
				{
					if (play[j][i] == 'X')
					{
						xCount++;
					}
				}

				if (xCount == 3)
				{
					victory = 'X';
					break;
				}
				else
				{
					xCount = 0;
				}

			}

			//Diagonal Victory
			if (play[0][0] == 'X' && play[1][1] == 'X' && play[2][2] == 'X')
			{
				victory = 'X';
				break;
			}
			if (play[2][0] == 'X' && play[1][1] == 'X' && play[0][2] == 'X')
			{
				victory = 'X';
				break;
			}
		}

		if (turn == 2)
		{
			//Player 2 instructions and input
			std::cout << "Player 2, you are 'O', choose where to place by entering two values. The first (0-2) determines the row, the second (0-2) determines the column.";
			std::cin >> row >> column;

			if (play[row][column] == ' ')
			{
				play[row][column] = 'O';
				turn--;
				turnCount++;
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
				for (int j = 0; j<3; j++)
				{
					if (play[i][j] == 'O')
					{
						oCount++;
					}
				}

				if (xCount == 3)
				{
					victory = 'O';
					break;
				}
				else
				{
					oCount = 0;
				}


			}
			//Vertical Victory
			for (int i = 0; i<3; i++)
			{
				for (int j = 0; j<3; j++)
				{
					if (play[j][i] == 'O')
					{
						oCount++;
					}
				}

				if (oCount == 3)
				{
					victory = 'O';
					break;
				}
				else
				{
					oCount = 0;
				}

			}

			//Diagonal Victory
			if (play[0][0] == 'O' && play[1][1] == 'O' && play[2][2] == 'O')
			{
				victory = 'O';
				break;
			}
			if (play[2][0] == 'O' && play[1][1] == 'O' && play[0][2] == 'O')
			{
				victory = 'O';
				break;
			}

		}
	}

	std::cout << "The winner is: " << victory << std::endl;

}
