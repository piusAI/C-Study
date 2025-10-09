#include <iostream>
using namespace std;

class Point {
    int x,y;
public:
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void showPoint() {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};

class ColorPoint: public Point {
    string color;
public:
    void setColor(string color) {this->color = color;}
    void showColorPoint();
};

void ColorPoint::showColorPoint() {
    cout<< color << ":";
    showPoint(); //point의 show point 호출
}

int main()
{
    Point p;
    ColorPoint cp;
    cp.set(3,4);          //base Class
    cp.setColor("Red");   //derive class
    cp.showColorPoint();  //derive Class >> base Class
    return 0;
}
