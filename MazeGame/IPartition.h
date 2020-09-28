#pragma once
#include "IRoom.h"
class IRoom;
class Point;
class IPartition
{
public:
	virtual void Draw(int x, int y, int RoomSize) = 0;
	virtual bool CanWalkThrough() = 0;
	virtual IRoom* GetRoomBehind() = 0;
};

