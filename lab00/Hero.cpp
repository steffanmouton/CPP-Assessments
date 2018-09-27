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