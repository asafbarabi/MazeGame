#pragma once
#include "IRoom.h"
#include "SideClass.h"
class IRoom;
class Point;
class IPartition
{
public:
	virtual void Draw(int x, int y, int RoomSize, Side side) = 0;
	virtual bool CanWalkThrough() = 0;
	virtual IRoom* GetRoomBehind() = 0;
	virtual void SetRoomBehind(IRoom* room) = 0;
	virtual IPartition* Clone() = 0;

};

