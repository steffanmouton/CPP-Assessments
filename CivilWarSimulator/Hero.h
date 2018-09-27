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
};