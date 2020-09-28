#include "Door.h"
#include <iostream>
using namespace std;

Door::Door(Side side):Partition(side){}

void Door::Draw(int x, int y, int roomSize)
{
	cout << "This is a Door on the " << sideNames[this->side]<<" side\n";
}

bool Door::CanWalkThrough()
{
	return true;
}
