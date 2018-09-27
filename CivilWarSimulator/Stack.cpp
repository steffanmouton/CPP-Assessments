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
	mData[mCount--] = nullptr;
	return 1;
}

Hero Stack::Top()
{
	//returns Top of target stack
	return  *mData[mCount-1];
}