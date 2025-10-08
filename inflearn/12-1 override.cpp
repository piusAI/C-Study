#include <iostream>
using namespace std;

class Point
{
    int x,y;
public:
    Point(int _x=0, int _y=0) : x(_x), y(_y){}
    void ShowPosition();
    Point operator+(const Point &p);
};

void Point::ShowPosition()
{
    cout<<x<<" "<<y<<endl;
}

Point Point::operator+(const Point &p) //const 참조, call by reference
{
    Point temp(x+p.x, y+p.y);
    return temp;
}

int main()
{
    Point p1(1,2);
    Point p2(2,1);
    // Point p3 = p1+p2;
    Point p3 = p1.operator+(p2);
    p3.ShowPosition();

    return 0;
}
