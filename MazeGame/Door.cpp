#include "Door.h"
#include <iostream>
using namespace std;

Door::Door(Side side):Partition(side){}

void Door::Draw()
{
	cout << "This is a Door on the " << sideNames[this->side]<<" side\n";
}
