#pragma once
#include "Partition.h"
class Door : public Partition
{
public:
	Door(Side side);
	bool CanWalkThrough();

	// Inherited via Partition
	void Draw(int x, int y, int RoomSize);
};