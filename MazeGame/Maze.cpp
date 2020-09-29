#include "Maze.h"

Maze::Maze(int playerRoomIndex, int treasureRoomIndex)
{
	//TODO sagi put this veriable in another location
	int treasureValue = rand() % 1000;
	//create Random doors and walls
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Rooms[5 * i + j] = new Room(CreateRandomPartition(up), CreateRandomPartition(down), CreateRandomPartition(right), CreateRandomPartition(left));
			Rooms[5 * i + j]->x = j ;
			Rooms[5 * i + j]->y = i;
			if (5 * i + j == treasureRoomIndex) {
				Rooms[5 * i + j]->treasure = treasureValue;
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

	int playerIndexX = playerRoomIndex % 5;
	int playerIndexY = playerRoomIndex / 5;
	int treasureIndexX = treasureRoomIndex % 5;
	int treasureIndexY = treasureRoomIndex / 5;
	int numberOfStpesRight = treasureIndexX - playerIndexX;
	int numberOfStepsDown = treasureIndexY - playerIndexY;

	int currentRoomIndex = playerRoomIndex;








	while (numberOfStpesRight != 0 || numberOfStepsDown != 0)
	{
		int typeOfMovment = rand() % 2;
		//up or down
		if (typeOfMovment == 0) {
			if (numberOfStepsDown > 0) {
				//TODO delete this partition before assinging it again
				Rooms[currentRoomIndex]->DownPartition = new Door(down);
				currentRoomIndex += 5;
				Rooms[currentRoomIndex]->DownPartition->SetRoomBehind(Rooms[currentRoomIndex]);
				numberOfStepsDown--;
			}
			else if (numberOfStepsDown < 0) {
				//TODO delete this partition before assinging it again
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
				//TODO delete this partition before assinging it again
				Rooms[currentRoomIndex]->RightPartition = new Door(right);
				currentRoomIndex += 1;
				Rooms[currentRoomIndex]->RightPartition->SetRoomBehind(Rooms[currentRoomIndex]);
				numberOfStpesRight--;
			}
			else if (numberOfStpesRight < 0) {
				//TODO delete this partition before assinging it again
				Rooms[currentRoomIndex]->LeftPartition = new Door(left);
				currentRoomIndex -= 1;
				Rooms[currentRoomIndex]->LeftPartition->SetRoomBehind(Rooms[currentRoomIndex]);
				numberOfStpesRight++;
			}
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
