#include <iostream>
#include <string>
using namespace std;

class Shape {
    int x, y;
public:
    Shape() {cout<<"Shape constructor"<<endl;}
    ~Shape() {cout<<"Shape destructor"<<endl;}
};

class Rectangle:public Shape {
    int width, height;

public:
    Rectangle() {cout<<"Rectangle constructor"<<endl;}
    ~Rectangle() {cout<<"Rectangle destructor"<<endl;}
};

int main() {
    Rectangle rect;
    return 0;

}
