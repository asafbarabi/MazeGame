#include "Wall.h"
#include<windows.h> 
#include<iostream>
#include "ConsoleDrawer.h"

using namespace std;
int WALL_SIZE = 1;
Wall::Wall() :Partition()
{

}
void Wall::Draw(int x, int y, int roomSize, Side side)
{
	ConsoleDrawer* consoleDrawer;
	consoleDrawer = consoleDrawer->GetInstance();
	if (side == Side::up || side == Side::down)
	{

		//Draw pixels
		for (int i = y; i < y + WALL_SIZE; i++)
		{
			for (int j = x; j < x + roomSize; j++)
			{
				consoleDrawer->WritePixel(j, i, 'X');
			}
		}
	}
	else
	{
		//Draw pixels
		for (int i = x; i < x + WALL_SIZE; i++)
		{
			for (int j = y; j < y + roomSize; j++)
			{
				consoleDrawer->WritePixel(i, j, 'X');
			}
		}
	}
}

bool Wall::CanWalkThrough()
{
	return false;
}
