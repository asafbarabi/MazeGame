#pragma once
#include "Partition.h"
class Wall : public Partition
{
public:
	Wall();
	void Draw(int x, int y, int RoomSize, Side side);
	bool CanWalkThrough();

	// Inherited via Partition
	virtual IPartition* Clone() override;
};