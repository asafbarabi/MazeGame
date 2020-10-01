#include "Maze.h"

Maze::Maze(Player* arrPlayers, Treasure* arrTreasure, int numPlayers, int roomSize)
{
	//create Random doors and walls

	IPartition* upPartition; IPartition* downPartition = nullptr; IPartition* rightPartition = nullptr; IPartition* leftPartition = nullptr;
	for (int i = 0; i < 25; i++)
	{
		if (i > 4)
			upPartition = Rooms[i - 5]->DownPartition->Clone();
		else
			upPartition = CreateRandomPartition(up);
		if (i != 0 && i != 5 && i != 10 && i != 15 && i != 20)
			leftPartition = rightPartition->Clone();
		downPartition = CreateRandomPartition(down);
		rightPartition = CreateRandomPartition(Side::right);

		if (i == 0 || i == 5 || i == 10 || i == 15 || i == 20)
		{
			leftPartition = CreateRandomPartition(Side::left);
		}
		Rooms[i] = new Room(upPartition, downPartition, rightPartition, leftPartition, roomSize);
		Rooms[i]->x = i % 5;
		Rooms[i]->y = i / 5;
	}

	//set roombehind
	for (int i = 0; i < 25; i++)
	{
		//Up Partiton room behind initialization
		if (i <= 4)
			Rooms[i]->UpPartition->SetRoomBehind(NULL);
		else
			Rooms[i]->UpPartition->SetRoomBehind(Rooms[i - 5]);

		//Down Partiton room behind initialization
		if (i >= 20)
			Rooms[i]->DownPartition->SetRoomBehind(NULL);
		else
			Rooms[i]->DownPartition->SetRoomBehind(Rooms[i + 5]);

		//Right partition room behind initialization
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24)
			Rooms[i]->RightPartition->SetRoomBehind(NULL);
		else
			Rooms[i]->RightPartition->SetRoomBehind(Rooms[i + 1]);

		//Left partition room behind initialization
		if (i == 0 || i == 5 || i == 10 || i == 15 || i == 20)
			Rooms[i]->LeftPartition->SetRoomBehind(NULL);
		else
			Rooms[i]->LeftPartition->SetRoomBehind(Rooms[i - 1]);


	}

	for (int i = 0; i < numPlayers; i++)
	{
		int playerIndexX = arrPlayers[i].CurrentRoomIndex % 5;
		int playerIndexY = arrPlayers[i].CurrentRoomIndex / 5;
		int treasureIndexX = arrTreasure[i].index % 5;
		int treasureIndexY = arrTreasure[i].index / 5;
		int numberOfStpesRight = treasureIndexX - playerIndexX;
		int numberOfStepsDown = treasureIndexY - playerIndexY;
		int currentRoomIndex = arrPlayers[i].CurrentRoomIndex;
		int typeOfMovment;
		while (numberOfStpesRight != 0 || numberOfStepsDown != 0)
		{

			if (numberOfStpesRight != 0 && numberOfStepsDown != 0)
				typeOfMovment = rand() % 2;
			else
			{
				if (numberOfStepsDown != 0)
					typeOfMovment = 0;
				else
					typeOfMovment = 1;
			}
			//up or down
			if (typeOfMovment == 0) {
				if (numberOfStepsDown > 0) {
					//delete this partition before assinging it again
					delete Rooms[currentRoomIndex]->DownPartition;

					Rooms[currentRoomIndex]->DownPartition = new Door();
					currentRoomIndex += 5;
					Rooms[currentRoomIndex]->UpPartition = new Door();
					Rooms[currentRoomIndex - 5]->DownPartition->SetRoomBehind(Rooms[currentRoomIndex]);
					Rooms[currentRoomIndex]->UpPartition->SetRoomBehind(Rooms[currentRoomIndex - 5]);
					numberOfStepsDown--;
				}
				else if (numberOfStepsDown < 0) {
					// delete this partition before assinging it again
					delete Rooms[currentRoomIndex]->UpPartition;
					Rooms[currentRoomIndex]->UpPartition = new Door();
					currentRoomIndex -= 5;
					Rooms[currentRoomIndex]->DownPartition = new Door();;
					Rooms[currentRoomIndex + 5]->UpPartition->SetRoomBehind(Rooms[currentRoomIndex]);
					Rooms[currentRoomIndex]->DownPartition->SetRoomBehind(Rooms[currentRoomIndex + 5]);
					numberOfStepsDown++;
				}
			}
			//left or right
			else
			{
				if (numberOfStpesRight > 0) {
					//delete this partition before assinging it again
					delete Rooms[currentRoomIndex]->RightPartition;
					Rooms[currentRoomIndex]->RightPartition = new Door();
					currentRoomIndex += 1;
					Rooms[currentRoomIndex]->LeftPartition = new Door();
					Rooms[currentRoomIndex - 1]->RightPartition->SetRoomBehind(Rooms[currentRoomIndex]);
					Rooms[currentRoomIndex]->LeftPartition->SetRoomBehind(Rooms[currentRoomIndex - 1]);
					numberOfStpesRight--;
				}
				else if (numberOfStpesRight < 0) {
					//delete this partition before assinging it again
					delete Rooms[currentRoomIndex]->LeftPartition;
					Rooms[currentRoomIndex]->LeftPartition = new Door();
					currentRoomIndex -= 1;
					Rooms[currentRoomIndex]->RightPartition = Rooms[currentRoomIndex + 1]->LeftPartition;
					Rooms[currentRoomIndex + 1]->LeftPartition->SetRoomBehind(Rooms[currentRoomIndex]);
					Rooms[currentRoomIndex]->RightPartition->SetRoomBehind(Rooms[currentRoomIndex + 1]);
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

void Maze::Draw(Player* players, Treasure* arrTreasure, int numPlayers)
{
	/*for (int i = 0; i < 25; i++)
	{
		Rooms[i]->Draw();
	}
	cout << endl;*/
	Draw(ConsoleDrawer::GetInstance()->GetY(), players, arrTreasure, numPlayers);
}

void Maze::Draw(int indentationYAxis, Player* players, Treasure* arrTreasure, int numPlayers)
{
	int mazeUpperLeftYPixel = ConsoleDrawer::GetInstance()->GetY();
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < numPlayers; j++)
		{
			if (arrTreasure[j].index == i)
				arrTreasure[j].Draw(Rooms[i]->GetRoomSize(), mazeUpperLeftYPixel);
			if (players[j].CurrentRoomIndex == i)
				players[j].Draw(players, arrTreasure, numPlayers, mazeUpperLeftYPixel);
		}
		Rooms[i]->Draw(Rooms[i]->GetIndexX(), Rooms[i]->GetIndexY(), indentationYAxis);
	}
	cout << endl;
}

IPartition* Maze::CreateRandomPartition(Side side)
{
	/* initialize random seed: */
	//srand(time(NULL));

	int randomNumber = rand() % 2;
	//return wall Partition
	if (randomNumber == 0) {
		return new Wall();
	}
	//return Door
	else {
		return new Door();
	}
}
