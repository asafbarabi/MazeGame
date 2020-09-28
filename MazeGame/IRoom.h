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

};

