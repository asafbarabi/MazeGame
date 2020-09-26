#pragma once
#include "IPartition.h"
#include "Room.h"
static const char* sideNames[] = { "up", "down", "left","right" };
enum Side
{
	up = 0,
	down,
	left,
	right
};

class Partition : public IPartition
{
public:
	Side side;
	Room* RoomBehind;

	Partition(Side side);
	Partition(Side side,Room* roomBehind);
	virtual void Draw() = 0;
	virtual bool CanWalkThrough() = 0;
};

