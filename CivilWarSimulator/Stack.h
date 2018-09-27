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