#include "Wall.h"
#include <iostream>
using namespace std;

Wall::Wall(Side side):Partition(side){}

void Wall::Draw(int x, int y, int roomSize)
{
	//cout << "This is a Wall on the " << sideNames[this->side]<<" side\n";
}

bool Wall::CanWalkThrough()
{
	return false;
}
