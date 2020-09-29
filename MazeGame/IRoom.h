#pragma once
#include "IPartition.h"
#include "SideClass.h"

class IPartition;
class Point;
class IRoom
{
public:
	virtual void Draw(int x, int y) = 0;
	virtual IPartition* GetPartition(Side side) = 0;
	virtual int GetTreasure() = 0;
	virtual int GetIndexX() = 0;
	virtual int GetIndexY() = 0;
	virtual int GetRoomSize() = 0;
};

