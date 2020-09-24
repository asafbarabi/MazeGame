#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

/// <summary>
/// Overloaded constructor with zero parameters
/// </summary>
Point::Point()
{
	//initialize the data members
	x = 0.0;
	y = 0.0;
}

/// <summary>
///    Overloaded constructor with two parameters
/// </summary>
/// <param name="x2"></param>
/// <param name="y2"></param>
Point::Point(double x2, double y2)
{
	//initialize the data members
	x = x2;
	y = y2;
	//cout<<*this<<endl;
}

#pragma region getters and setters

void Point::setX(double x2)
{
	x = x2;
}

void Point::setY(double y2) {
	y = y2;
}

//get (accessor) functions   
double Point::getX() {
	return x;

}

double Point::getY() {
	return y;
}

#pragma endregion

/// <summary>
/// Returns the distance from point (0,0).
/// Can be the magnitude of a vector or length of a line.
/// </summary>
/// <returns></returns>
double Point::distance()
{
	return sqrt(x * x + y * y);
}


