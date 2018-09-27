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
		//Fights top of Team 1 stack vs top of Team 2 stack
		Game::Resolution result = Arena.Battle((Hero&)Team1.Top(), (Hero&)Team2.Top());

		//Set pointers to winner and loser of battle
		Hero* wPtr = &(result.winner);
		Hero* lPtr = &(result.loser);

		//Push winnerss 
		Winners.Push(wPtr);
		Losers.Push(lPtr);

		Team1.Pop();
		Team2.Pop();

		std::cout << "\n\nBattle: " << i+1 << "\nThe winner is: " << result.winner.Info() << std::endl
			<< "\nThe loser is: " << result.loser.Info() << std::endl;
	}
}