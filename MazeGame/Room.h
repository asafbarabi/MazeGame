#pragma once
#include "IPartition.h"
#include "point.h"
class Room
{
public:
	IPartition* UpPartition;
	IPartition* DownPartition;
	IPartition* RightPartition;
	IPartition* LeftPartition;
	Room(IPartition* upPartition, IPartition* downPartition, IPartition* rightPartition, IPartition* leftPartition);
	void Draw();
};

