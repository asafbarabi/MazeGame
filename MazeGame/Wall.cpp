#include "Wall.h"
#include <iostream>
using namespace std;

Wall::Wall(Side side):Partition(side){}

void Wall::Draw()
{
	cout << "This is a Wall on the " << sideNames[this->side]<<" side\n";
}
