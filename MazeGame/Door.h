#pragma once
#include "Partition.h"
class Door : public Partition
{
public:
	Door(Side side);
	void Draw();
};