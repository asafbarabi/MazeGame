#pragma once
#include "IPartition.h"
#include "SideClass.h"
class IPartition;
class IRoom
{
public:
	virtual void Draw() = 0;
	virtual IPartition* GetPartition(Side side) = 0;

};

