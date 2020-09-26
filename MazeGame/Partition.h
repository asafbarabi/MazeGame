#pragma once
#include "IPartition.h"
#include "IRoom.h"
#include "SideClass.h"
#include "Point.h"


class Partition : public IPartition
{
public:
	Side side;
	IRoom* RoomBehind;

	Partition(Side side);
	Partition(Side side,IRoom* roomBehind);
	virtual void Draw(Point* Location, int RoomSize) = 0;
	virtual bool CanWalkThrough() = 0;

	// Inherited via IPartition
	virtual IRoom* GetRoomBehind() override;
};

