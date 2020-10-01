#include "Treasure.h"
#include "ConsoleDrawer.h"

Treasure::Treasure(int value, int index) {
	this->index = index;
	this->value = value;
}
void Treasure::Draw(int roomSize)
{
	int previousY = ConsoleDrawer::GetInstance()->GetY();
	int PixelX = (index % 5) * roomSize;
	int PixelY = (index / 5) * roomSize;
	ConsoleDrawer::GetInstance()->WriteString(PixelX + 2, PixelY + 1, to_string(this->value));
	ConsoleDrawer::GetInstance()->SetConsoleCurserCoordinate(0, previousY);
}
void Treasure::Draw(int roomSize, int indentationYAxis)
{
	int previousY = ConsoleDrawer::GetInstance()->GetY();
	int PixelX = (index % 5) * roomSize;
	int PixelY = (index / 5) * roomSize;
	ConsoleDrawer::GetInstance()->WriteString(PixelX + 2, PixelY + 1 + indentationYAxis, to_string(this->value));
	ConsoleDrawer::GetInstance()->SetConsoleCurserCoordinate(0, previousY);

}

