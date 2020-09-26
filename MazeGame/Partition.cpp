#include "Partition.h"
#include <iostream>
using namespace std;

Partition::Partition(Side side)
{
	this->side = side;
	this->RoomBehind = nullptr;
}

Partition::Partition(Side side, IRoom* roomBehind):Partition(side)
{
	this->RoomBehind = roomBehind;
}

bool Partition::CanWalkThrough()
{
	return false;
}

IRoom* Partition::GetRoomBehind()
{
	return this->RoomBehind;
}

