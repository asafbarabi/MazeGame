#pragma once
#include "IPartition.h"

class IPartition;
class Point;
class IRoom
{
public:
	virtual void Draw(int x, int y) = 0;
	virtual void Draw(int x, int y, int indentationYAxis) = 0;

	virtual IPartition* GetLeftPartition() = 0;
	virtual IPartition* GetRightPartition() = 0;
	virtual IPartition* GetUpPartition() = 0;
	virtual IPartition* GetDownPartition() = 0;
	virtual int GetIndexX() = 0;
	virtual int GetIndexY() = 0;
	virtual int GetRoomSize() = 0;
};

