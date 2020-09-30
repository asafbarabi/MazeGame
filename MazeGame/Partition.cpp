#include "Partition.h"
#include <iostream>
using namespace std;

Partition::Partition()
{
	this->RoomBehind = nullptr;
}


Partition::~Partition()
{
	delete RoomBehind;
}

Partition::Partition( IRoom* roomBehind)
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

void Partition::SetRoomBehind(IRoom* room)
{
	//put if can't Walk through throw exception
	RoomBehind = room;
}

