#pragma once
#include "IPartition.h"
#include "IRoom.h"
#pragma once
class Room : public IRoom
{
public:
	//the upper left of the room from a maze of size 5X5
	int x, y;
	int RoomSize;
	IPartition* UpPartition;
	IPartition* DownPartition;
	IPartition* RightPartition;
	IPartition* LeftPartition;

	
	Room(IPartition* upPartition, IPartition* downPartition, IPartition* rightPartition, IPartition* leftPartition, int roomSize);
	~Room();

	// Draw room on specific x and y
	void Draw(int x, int y);
	
	// Draw room on your x and y 
	void Draw();

	//TODO Sagie add setters

	// Inherited via IRoom
	virtual void Draw(int x, int y, int indentationYAxis) override;
	
	virtual int GetIndexX() override;

	virtual int GetIndexY() override;

	virtual int GetRoomSize() override;


	// Inherited via IRoom
	virtual IPartition* GetLeftPartition() override;

	virtual IPartition* GetRightPartition() override;

	virtual IPartition* GetUpPartition() override;

	virtual IPartition* GetDownPartition() override;

};

