#pragma once
#include "Partition.h"
class Wall : public Partition
{
public:
	Wall(Side side);
	void Draw(Point* location, int roomSize);
	bool CanWalkThrough();
};