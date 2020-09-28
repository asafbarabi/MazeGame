#include "Door.h"
#include<windows.h>
#include<iostream>
#include <cmath>
#include "ConsoleDrawer.h"
using namespace std;
int DOOR_SIZE = 1;

Door::Door(Side side) :Partition(side) {}


void Door::Draw(int x, int y, int roomSize)
{
	ConsoleDrawer* consoleDrawer;
	consoleDrawer = consoleDrawer->GetInstance();

	if (this->side == Side::up || this->side == Side::down)
	{
		//Draw pixels
		for (int i = y + 0; i < y + DOOR_SIZE; i++)
		{
			for (int j = x; j < x + roomSize; j++)
			{
				consoleDrawer->WritePixel(j, i, '.');
			}
		}
	}
	else
	{
		//Draw pixels
		for (int i = x; i < x + DOOR_SIZE; i++)
		{
			for (int j = y; j < y + roomSize; j++)
			{
				consoleDrawer->WritePixel(j, i, '.');
			}
		}
	}
}

bool Door::CanWalkThrough()
{
	return true;
}
