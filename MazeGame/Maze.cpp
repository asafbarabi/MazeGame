#include "Maze.h"

Maze::Maze()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Rooms[5 * i + j] = new Room(CreateRandomPartition(up), CreateRandomPartition(down), CreateRandomPartition(right), CreateRandomPartition(left));
			Rooms[5 * i + j]->x = i * 8;
			Rooms[5 * i + j]->y = j * 8;
		}
	}
}


void Maze::Draw()
{
	for (int i = 0; i < 25; i++)
	{
		Rooms[i]->Draw();
	}
}

IPartition* Maze::CreateRandomPartition(Side side)
{
	/* initialize random seed: */
	//srand(time(NULL));

	int randomNumber = rand() % 2;
	//return wall Partition
	if (randomNumber == 0) {
		return new Wall(side);
	}
	//return Door
	else {
		return new Door(side);
	}
}
