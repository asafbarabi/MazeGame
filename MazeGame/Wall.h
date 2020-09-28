#pragma once
#include "Partition.h"
class Wall : public Partition
{
public:
	Wall(Side side);
	void Draw(int x, int y, int RoomSize);
	bool CanWalkThrough();
};