#pragma once
class Point
{
public :
    Point();
    Point(double x2, double y2);
    double distance();
    void setX(double x2);
    void setY(double y2);
    double getX();
    double getY();

    /*//friend function for overloading output operator<<()
    friend ostream& operator<<(ostream& output, const Point& point) {
        output << "(" << point.x << ", " << point.y << ")";
        return output;
    }*/
    
protected:
    double x;
    double y;
};

