#include <iostream>
#include <time.h>

int main()
{
	srand(time(NULL));
	int guess = 0;
	char input = ' ';

	std::cout << "Think of a number between 1 and 20\n Press Enter to continue. \n";
	system("pause");


	int minGuess = 0;
	int maxGuess = 20;
	guess = rand() % (maxGuess - minGuess + 1) + minGuess;

	while (input != 'E' || 'e')
	{
		std::cout << "Is your number '>', '<', or '=' to " << guess << "?\n Input 'E' at any time to exit. \n";
		std::cin >> input;

		switch (input)
		{
		case '>':
			minGuess = guess;
			guess = rand() % (maxGuess - minGuess) + (minGuess + 1);
			break;
		case '<':
			maxGuess = guess;
			guess = rand() % (maxGuess - minGuess) + minGuess;
			break;
		case '=':
			std::cout << "The number you chose was " << guess << ".\n";
			system("pause");
			return 0;
		case 'E':
			return 0;
		case 'e':
			return 0;
		}

	}

}