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

	Resolution Battle(Hero& h1, Hero& h2);

	
};