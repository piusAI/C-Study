#include <iostream>
#include <string>
using namespace std;

class Shape {
    int x, y;
public:
    Shape() {cout<<"Shape constructor"<<endl;}
    Shape(int xloc, int yloc):x(xloc), y(yloc) {
        cout<<"Shape constructor (xloc, yloc)"<<endl;
    }
    ~Shape() {cout<<"Shape destructor"<<endl;}
};

class Rectangle:public Shape {
    int width, height;

public:
    Rectangle(int x, int y, int w,int h):Shape(x,y){width = w, height = h;}
    ~Rectangle() {cout<<"Rectangle destructor"<<endl;}
};

int main() {
    Rectangle rect(0,0,100,100);
    return 0;

}
