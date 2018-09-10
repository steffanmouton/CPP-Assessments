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
