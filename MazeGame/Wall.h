#pragma once
#include "Partition.h"
class Wall : public Partition
{
public:
	Wall(Side side);
	void Draw();
};