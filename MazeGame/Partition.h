#pragma once
#include "IPartition.h"
#include "IRoom.h"
#include "SideClass.h"


class Partition : public IPartition
{
public:
	IRoom* RoomBehind;

	Partition();
	~Partition();
	Partition(IRoom* roomBehind);
	virtual void Draw(int x, int y, int RoomSize,Side side) = 0;
	virtual bool CanWalkThrough() = 0;

	// Inherited via IPartition
	virtual IRoom* GetRoomBehind() override;

	// Inherited via IPartition
	virtual void SetRoomBehind(IRoom* room) override;

	// Inherited via IPartition
	virtual IPartition* Clone() override = 0;
};

