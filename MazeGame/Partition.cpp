#include "Partition.h"
#include <iostream>
using namespace std;


Partition::Partition(Side side)
{
	this->side = side;
}

void Partition::Draw()
{
	cout << "drew" << sideNames[this->side] << "partition";
}

bool Partition::CanWalkThrough()
{
	return false;
}
