#include "Game.h"

//each hero deals damage to the other, whoever is left 
//with more health is returned as winner

//Resolution structure - returns a Resolution that contains both winner and loser
//Allows for later reference of winner and loser to allow for pushing onto proper stacks
Game::Resolution Game::Battle(Hero & h1, Hero & h2)
{
	Hero winner;
	Resolution res;

	//Heros hit each other using the Fight method
	h1.Fight(h2);
	h2.Fight(h1);


	//Winner = Higher HP
	if (h1 > h2)
	{
		res.winner = h1;
		res.loser = h2;
	}
	else
	{
		res.winner = h2;
		res.loser = h1;
	}

	return res;
}