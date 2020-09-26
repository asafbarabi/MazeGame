#pragma once
#include "IRoom.h"
class IRoom;
class IPartition
{
public:
	virtual void Draw() = 0;
	virtual bool CanWalkThrough() = 0;
	virtual IRoom* GetRoomBehind() = 0;
};

