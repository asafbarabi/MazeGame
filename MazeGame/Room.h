#pragma once
#include "IPartition.h"
#include "IRoom.h"
#pragma once
class Room : public IRoom
{
public:
	//the upper left of the room 
	int x, y;
	int RoomSize;
	IPartition* UpPartition;
	IPartition* DownPartition;
	IPartition* RightPartition;
	IPartition* LeftPartition;

	Room(IPartition* upPartition, IPartition* downPartition, IPartition* rightPartition, IPartition* leftPartition);
	Room(IPartition* upPartition, IPartition* downPartition, IPartition* rightPartition, IPartition* leftPartition, int roomSize);

	void Draw(int x, int y);

	//TODO Sagie add getters and setters



	// Inherited via IRoom
	virtual IPartition* GetPartition(Side side) override;

};

