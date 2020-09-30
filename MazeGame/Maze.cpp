#include "Maze.h"
#include "Player.h"

Maze::Maze(Player* arrPlayers, Treasure* arrTreasure, int numPlayers)
{
	//create Random doors and walls
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Rooms[5 * i + j] = new Room(CreateRandomPartition(up), CreateRandomPartition(down), CreateRandomPartition(right), CreateRandomPartition(left));
			Rooms[5 * i + j]->x = j;
			Rooms[5 * i + j]->y = i;
			for (int t = 0; t < numPlayers; t++)
			{
				if (5 * i + j == arrTreasure[t].index) {
					Rooms[5 * i + j]->treasure = arrTreasure[t].value;
				}
			}
		}
	}

	//TODO add function to add SetRoomBehind to every room
	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (((5 * i + j) > -1) && ((5 * i + j) < 6)) {
				Rooms[5 * i + j]->RightPartition->SetRoomBehind(Rooms[5 * i + j]);
			}
		}
	}*/

	for (int i = 0; i < numPlayers; i++)
	{


		int playerIndexX = arrPlayers[i].startRoom % 5;
		int playerIndexY = arrPlayers[i].startRoom / 5;
		int treasureIndexX = arrTreasure[i].index % 5;
		int treasureIndexY = arrTreasure[i].index / 5;
		int numberOfStpesRight = treasureIndexX - playerIndexX;
		int numberOfStepsDown = treasureIndexY - playerIndexY;
		int currentRoomIndex = arrPlayers[i].startRoom;

		while (numberOfStpesRight != 0 || numberOfStepsDown != 0)
		{
			int typeOfMovment = rand() % 2;
			//up or down
			if (typeOfMovment == 0) {
				if (numberOfStepsDown > 0) {
					//delete this partition before assinging it again
					delete Rooms[currentRoomIndex]->DownPartition;
					Rooms[currentRoomIndex]->DownPartition = new Door(down);
					currentRoomIndex += 5;
					Rooms[currentRoomIndex]->DownPartition->SetRoomBehind(Rooms[currentRoomIndex]);
					numberOfStepsDown--;
				}
				else if (numberOfStepsDown < 0) {
					// delete this partition before assinging it again
					delete Rooms[currentRoomIndex]->UpPartition;
					Rooms[currentRoomIndex]->UpPartition = new Door(up);
					currentRoomIndex -= 5;
					Rooms[currentRoomIndex]->UpPartition->SetRoomBehind(Rooms[currentRoomIndex]);
					numberOfStepsDown++;
				}
			}
			//left or right
			else
			{
				if (numberOfStpesRight > 0) {
					//delete this partition before assinging it again
					delete Rooms[currentRoomIndex]->RightPartition;
					Rooms[currentRoomIndex]->RightPartition = new Door(right);
					currentRoomIndex += 1;
					Rooms[currentRoomIndex]->RightPartition->SetRoomBehind(Rooms[currentRoomIndex]);
					numberOfStpesRight--;
				}
				else if (numberOfStpesRight < 0) {
					//delete this partition before assinging it again
					delete Rooms[currentRoomIndex]->LeftPartition;
					Rooms[currentRoomIndex]->LeftPartition = new Door(left);
					currentRoomIndex -= 1;
					Rooms[currentRoomIndex]->LeftPartition->SetRoomBehind(Rooms[currentRoomIndex]);
					numberOfStpesRight++;
				}
			}
		}
	}

}

Maze::~Maze()
{
	for (int i = 0; i < 25; i++)
	{
		delete this->Rooms[i];
	}
	delete this->Rooms;
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
