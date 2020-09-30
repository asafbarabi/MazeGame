#pragma once
#include "IPartition.h"
#include "IRoom.h"
#include "SideClass.h"


class Partition : public IPartition
{
public:
	Side side;
	IRoom* RoomBehind;

	Partition(Side side);
	~Partition();
	Partition(Side side,IRoom* roomBehind);
	virtual void Draw(int x, int y, int RoomSize) = 0;
	virtual bool CanWalkThrough() = 0;

	// Inherited via IPartition
	virtual IRoom* GetRoomBehind() override;

	// Inherited via IPartition
	virtual void SetRoomBehind(IRoom* room) override;
};

