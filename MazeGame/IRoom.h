#pragma once
#include "IPartition.h"
#include "SideClass.h"
class IPartition;
class Point;
class IRoom
{
public:
	virtual void Draw(Point* Location) = 0;
	virtual IPartition* GetPartition(Side side) = 0;

};

