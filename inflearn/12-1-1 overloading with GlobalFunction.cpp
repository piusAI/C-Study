#include <iostream>
using namespace std;

class Point
{
    int x,y;
public:
    Point(int _x=0, int _y=0) : x(_x), y(_y){}
    void ShowPosition();

     //전역함수로써 받음
    friend Point operator+(const Point &a, const Point &b);
};

void Point::ShowPosition()
{
    cout<<x<<" "<<y<<endl;
}

Point operator+(const Point &p1, const Point &p2)
{
    Point temp(p1.x+p2.x, p1.y+p2.y);
    return temp;
}

int main()
{
    Point p1(4,4);
    Point p2(2,1);
    Point p3 = operator+(p1,p2);
    p3.ShowPosition();
    return 0;
}
