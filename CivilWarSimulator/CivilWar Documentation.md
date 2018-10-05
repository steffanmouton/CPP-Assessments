# Civil War Simulator Documentation

Steffan Mouton

s188045

IntroCPP Assessment

## Requirements Documentation

- Description of Problem
  - Name: Civil War Simulator
  - Problem Statement: Create a program that utilizes stack classes to simulate two teams fighting against each other.
  - Problem Specification: Create a simulator that fights the two sides of Marvel's Civil War. Must use a simulated stack implementation, holding Team1, Team2, Winners, and Losers.
  Must contain the following Classes: Stack, Hero, Game. As per Mr. Matthew, I was to push my Heros onto their original team stacks, then have the top of each stack fight each other.
  The winner and loser, as determined by remaining hp, are to be returned via a new DTO called Resolution. The winner is then pushed onto the Winner Stack, and the loser pushed onto the Loser stack. Then, the top of
  the Team stacks are popped off, allowing the next heros to be on top of the stack and the cycle continues until all heros have fought. After all combat is completed, the Winners and Losers are then printed to console from their stacks, displaying their name and HP.

- Input Information
  - N/A
- Output Information
  - Simulator runs all at once. Will print to console results of each battle, including winner and loser, and their remaining hp.

- User Interface Information
  - Description: The user does not interact with the program, except to launch it and close it.

## Design Documentation

- System Architecture Description
  - [Click here to view PDF of Architecture](https://drive.google.com/file/d/1ucHW4sUaIahvpzIl0J-Dh99hu6Z5PdED/view?usp=sharing)
- Information about the objects
  - *Class Information*
    - Name: Hero
      - Description: Contains data for each "Hero" fighter in our simulation
      - Base Class: NA
      - Class Attributes
        - Name: mHealth
          - Description: The current HP of the fighter
          - Type: int
          - Range of Acceptable Values: All int values
        - Name: mPower
          - Description: The randomly generated value for damage a hero can deal to another
          - Type: int
          - Range of Acceptable Values: All int values
        - Name: mName
          - Description: The name of the Hero
          - Type: string
          - Range of Acceptable Values: Characters in a string
      - Class Operations
        - Prototype: Hero(); AND Hero(std::string);
          - Description: Default constructor and constructor that takes in a name
          - Pre-Conditions: New instance of Hero is being generated
          - Post-Conditions: New hero has hp of 100, randomly generated power value, and a Name
          - Visibility: Public
        - Prototype: std::string Info();
          - Description: Prints out the name and HP of the hero calling the function
          - Pre-Conditions: Hero exists and is calling function
          - Post-Conditions: Print to console Hero's current Name and HP
          - Visibility: Public
        - Prototype: void Fight(Hero& hero);
          - Description: Makes one hero Fight another hero and call the TakeDamage function
          - Pre-Conditions: Two heros exist and are called together in a Battle function
          - Post-Conditions: Each hero deals damage to the other
          - Visibility: Public
        - Prototype: void TakeDamage(int power);
          - Description: Makes one hero decrement their own hp by the inputted power value
          - Pre-Conditions: Two heros exist and are called together in a Battle function and the Fight function
          - Post-Conditions: Hero hp is decremented by power value
          - Visibility: Public
        - Prototype: Hero operator = (const Hero& rhs); AND bool operator > (const Hero& rhs); AND bool operator < (const Hero& rhs);
          - Description: Operator Overloading, to ensure transfer of data when assigning one hero to another and for comparing HP values in a Battle
          - Pre-Conditions: Two heros exist and are being assigned or compared
          - Post-Conditions: All data is transferred or hp is compared, determining winner
          - Visibility: Public
    - Name: Stack
      - Description: Simulates a stack to hold the fighters in starting teams and their winner/loser groups
      - Base Class: NA
      - Class Attributes
        - Name: mData[20];
          - Description: Stack Array that holds Heros
          - Type: Hero*
          - Range of Acceptable Values: Any Hero
        - Name: mCount
          - Description: To keep track of the current place in the array
          - Type: int
          - Range of Acceptable Values: All int values 0 to 20
      - Class Operations
        - Prototype: Stack()
          - Description: Default constructor to set mCount to 0
          - Pre-Conditions: New instance of Stack is being created
          - Post-Conditions: New Stack is created, with mCount set to 0
          - Visibility: Public
        - Prototype: bool Pop();
          - Description: Removes the current top of the Stack and decrements mCount
          - Pre-Conditions: Stack exists and is calling function
          - Post-Conditions: Remove the Hero at the top of the stack, decrement mCount
          - Visibility: Public
        - Prototype: bool Push(Hero* h);
          - Description: Pushes a target Hero to the top of the Stack calling this function
          - Pre-Conditions: A Hero and a Stack exist
          - Post-Conditions: Targetted hero is on top of the stack
          - Visibility: Public
    - Name: Game
      - Description: Simulates a stack to hold the fighters in starting teams and their winner/loser groups
      - Base Class: NA
      - Class Attributes
        - Name: Resolution
          - Description: Struct to hold the return of the Battle function, which is a winner and a loser
          - Type: Resolution
      - Class Operations
        - Prototype: Resolution* Battle(Hero& h1, Hero& h2);
          - Description: Puts two heros into an arena and makes them fight, returning a winner and loser determined by comparing HP
          - Pre-Conditions: Two Heroes exist
          - Post-Conditions:  New Resolution is created, storing winner and loser
          - Visibility: Public

## Implementation Documentation

- Program Code

- Hero.h
  
```C++
#pragma once
#include <iostream>
#include <time.h>
#include <string>


class Hero
{
private:
	int mHealth;
	int mPower;
	std::string mName;

public:
	//Default Constructor
	Hero();
	Hero(std::string);

	//Prints name and HP of hero called
	std::string Info();

	//Makes heroes interact and deal damage to eachother, via TakeDamage function
	void Fight(Hero& hero);

	//Causes hero to reduce its own hp based on power value of hero it is in Fight() with
	void TakeDamage(int power);

	//Operator Overloading to compare hero HP values, determines winner.
	bool operator > (const Hero& rhs);
	bool operator < (const Hero& rhs);

	//Operator Overloading to make all parts of one hero assign to another
	Hero operator = (const Hero& rhs);
}
```

- Hero.cpp
  
```C++
#include "Hero.h"
//removes health of amt power
void Hero::TakeDamage(int power)
{
	mHealth -= power;
}

//Operator Overloading to compare HP of Heroes
bool Hero::operator>(const Hero& rhs)
{
	return (this->mHealth > rhs.mHealth);
}
bool Hero::operator<(const Hero & rhs)
{
	return (this->mHealth < rhs.mHealth);
}


//Operator Overloading to assign all parts of one hero to another
Hero Hero::operator=(const Hero & rhs)
{
	this->mHealth = rhs.mHealth;
	this->mPower = rhs.mPower;
	this->mName = rhs.mName;
	return Hero();
}

//Assigns hero HP to 100 and
//assigns random power to each fighter between values 10 - 30
Hero::Hero()
{
	mHealth = 100;
	mPower = rand() % (30 - 10 + 1) + 10;

}

//Construct hero with a name string
Hero::Hero(std::string Name) :Hero()
{
	mName = Name;
}

//Prints current info of a hero.
std::string Hero::Info()
{
	std::string info="";

	info.append("\nName: " + mName);
	info.append("\nHealth:: " + std::to_string(mHealth));
	return info;
}

//Applies TakeDamage function to the hero
void Hero::Fight(Hero & hero)
{
	hero.TakeDamage(mPower);
}
```

- Class.h

```C++
#pragma once
#include "Hero.h"

class Game
{
private:

public:
	//Returning both winner and loser via DTO (Data Transfer Object)
	struct Resolution
	{
		Hero winner;
		Hero loser;
	};

	Resolution* Battle(Hero& h1, Hero& h2);

	
};
```

- Game.cpp
  
```C++
#include "Game.h"

//each hero deals damage to the other, whoever is left 
//with more health is returned as winner

//Resolution structure - returns a Resolution that contains both winner and loser
//Allows for later reference of winner and loser to allow for pushing onto proper stacks
Game::Resolution* Game::Battle(Hero & h1, Hero & h2)
{
	Hero winner;
	Resolution* res = new Resolution;

	//Heros hit each other using the Fight method
	h1.Fight(h2);
	h2.Fight(h1);


	//Winner = Higher HP
	if (h1 > h2)
	{
		res->winner = h1;
		res->loser = h2;
	}
	else
	{
		res->winner = h2;
		res->loser = h1;
	}

	return res;
}
```

- Stack.h

```C++
#pragma once
#include "Hero.h"

class Stack
{
	//Stacks that can hold heroes
private:
	Hero* mData[20];
	int mCount;

public:
	Stack()
	{
		mCount = 0;
	}

	Hero Top();

	bool Pop();

	bool Push(Hero* h);
};
```

- Stack.cpp

```C++
#include "Stack.h"

bool Stack::Push(Hero* hero)
{
	//Adds hero to top of target stack
	mData[mCount++] = hero;
	return 1;
}

bool Stack::Pop()
{
	//Pop off the top of the target stack
	mData[--mCount] = nullptr;
	return 1;
}

Hero Stack::Top()
{
	//returns Top of target stack
	return  *mData[mCount-1];
}
```

- Source.cpp

```C++
#include <iostream>
#include "Stack.h"
#include "Hero.h"
#include "Game.h"

int main()
{
	srand(time(NULL));
	
	//Initializing all heroes and their pointers
	Hero* IronMan = new Hero("IronMan");	
	Hero* Panther = new Hero("BlackPanther");	
	Hero* Machine = new Hero("WarMachine");	
	Hero* Spidey = new Hero("SpiderMan");
	Hero* Vision = new Hero("Vision");
	Hero* Cap = new Hero("CaptainAmerica");
	Hero* Hawkeye = new Hero("Hawkeye");
	Hero* Falcon = new Hero("Falcon");
	Hero* Bucky = new Hero("WinterSoldier");
	Hero* AntMan = new Hero("AntMan");

	//Initializing the battle arena function
	Game Arena;

	//Initializing the team and result stacks
	Stack Team1;
	Stack Team2;
	Stack Winners;
	Stack Losers;

	//Pushing the heroes to their Starting Teams
	Team1.Push(IronMan);
	Team1.Push(Panther);
	Team1.Push(Machine);
	Team1.Push(Spidey);
	Team1.Push(Vision);

	Team2.Push(Cap);
	Team2.Push(Hawkeye);
	Team2.Push(Falcon);
	Team2.Push(Bucky);
	Team2.Push(AntMan);


	//Battle Team 1 vs Team 2, push Winners into Winner Stack and Losers into Loser Stack
	for (int i = 0; i < 5; i++)
	{
		//Pointers to top of each stack
		Hero ref1 = Team1.Top();
		Hero ref2 = Team2.Top();

		//Fights top of Team 1 stack vs top of Team 2 stack
		Game::Resolution* result = Arena.Battle(ref1, ref2);

		//Set pointers to winner and loser of battle
		Hero* wPtr = &(result->winner);
		Hero* lPtr = &(result->loser);

		//Push winners and losers to their respective stacks
		Winners.Push(wPtr);
		Losers.Push(lPtr);

		//remove the top of each stack from the teams after 
		Team1.Pop();
		Team2.Pop();

		std::cout << "\n\nBattle: " << i+1 << "\n\nThe winner is: " << result->winner.Info() << std::endl
			<< "\nThe loser is: " << result->loser.Info() << std::endl;
	}

	//Print out the Winners and the Losers

	std::cout << "\n After all combat, \nThe Winners are:\n";

	for (int i = 0; i < 5; i++)
	{
		std::cout << Winners.Top().Info();
		Winners.Pop();
	}

	std::cout << "\n\nThe Losers are:\n";

	for (int i = 0; i < 5; i++)
	{
		std::cout << Losers.Top().Info();
		Losers.Pop();
	}
	system("pause");
}
```
