# Number Guessing Game Documentation

Steffan Mouton

s188045

IntroCPP Assessment

## Requirements Documentation

- Description of Problem
  - Name: Number Guessing Game
  - Problem Statement: Create a program that correctly identifies the number a user is thinking.
  - Problem Specification: User will think of a number. Once the User has thought of a number, they will tell the computer to start guessing. Computer prints a number guess to the console. After each guess, User tells the computer if the guessed number is less than, greater than, or equal to the number the User is thinking of. Program finishes when computer has guessed the correct number or the app is forced to quit. Must use variables, conditions, and loops.
    Program will finish when app is forced to quit, a player has won, or the draw condition is met.
    Must use variables, conditionals, loops, and arrays.

- Input Information
  - N/A

- Output Information
  - Computer prints guesses to console after user feedback.

- User Interface Information
  - Description: All interface occurs in the console. User is required to press a key to start the program. From there, the user can input <, >, or = to tell the computer how its guess compares to the User’s chosen number. They may also enter  ‘E’ or ‘e’ to exit the program.

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
```