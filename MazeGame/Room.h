#pragma once
#include "Partition.h"
#include "point.h"
class Room
{
public:
	Room(Partition* upPartition, Partition* downPartition, Partition* rightPartition, Partition* leftPartition);
	void Draw();
private:
	Point Location;
	Partition* UpPartition;
	Partition* DownPartition;
	Partition* RightPartition;
	Partition* LeftPartition;
};

