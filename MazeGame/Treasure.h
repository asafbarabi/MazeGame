#pragma once
class Treasure
{
public:
	int value;
	int index;

	Treasure(int value=0, int index=0);
	void Draw(int roomSize );
	void Draw(int roomSize, int indentationYAxis);

private:
};



