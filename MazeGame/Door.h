#pragma once
#include "Partition.h"
class Door : public Partition
{
public:
	Door();
	bool CanWalkThrough();

	// Inherited via Partition
	void Draw(int x, int y, int RoomSize, Side side);
};