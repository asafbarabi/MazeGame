#pragma once
class IPartition
{
public:
	virtual void Draw() = 0;
	virtual bool CanWalkThrough() = 0;
};

