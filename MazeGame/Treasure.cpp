#include "Treasure.h"
#include "ConsoleDrawer.h"

Treasure::Treasure(int value, int index) {
	this->index = index;
	this->value = value;
}
void Treasure::Draw(int roomSize)
{
	ConsoleDrawer* consoleDrawer;
	consoleDrawer = consoleDrawer->GetInstance();
	int PixelX = (index % 5) * roomSize;
	int PixelY = (index / 5) * roomSize;

	consoleDrawer->WriteString(PixelX+2, PixelY+1, to_string(this->value));
}
