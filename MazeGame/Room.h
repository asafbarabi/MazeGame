#pragma once
#include "IPartition.h"
#include "point.h"
#include "IRoom.h"
class Room : public IRoom
{
public:

	//Point Location;
	IPartition* UpPartition;
	IPartition* DownPartition;
	IPartition* RightPartition;
	IPartition* LeftPartition;

	Room(IPartition* upPartition, IPartition* downPartition, IPartition* rightPartition, IPartition* leftPartition);
	void Draw();

	//TODO Sagie add getters and setters



	// Inherited via IRoom
	virtual IPartition* GetPartition(Side side) override;

};

