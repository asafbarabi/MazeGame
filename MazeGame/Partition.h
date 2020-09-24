#pragma once

static const char* sideNames[] = { "up", "down", "left","right" };
enum Side
{
	up = 0,
	down,
	left,
	right
};

class Partition
{
public:
	Side side;

	Partition(Side side);
	virtual void Draw();
};

