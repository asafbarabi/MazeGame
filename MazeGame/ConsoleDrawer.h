#pragma once
#include<windows.h> 
#include<iostream>
using namespace std;

class ConsoleDrawer
{
private:
	COORD coord;
public:
	ConsoleDrawer();
	void WritePixel(int x, int y, char charToDraw);

	//singleton
	static ConsoleDrawer* GetInstance();
	ConsoleDrawer(ConsoleDrawer const&) = delete;
	void operator=(ConsoleDrawer const&) = delete;


};

