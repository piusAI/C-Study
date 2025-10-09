#include <iostream>
#include <string>

using namespace std;

class Shape {
    int x, y;
public:
    void setX(int xval) {
        x= xval;
    }
    void setY(int yval) {
        y = yval;
    }
};

class Rectangle:public Shape {
    int width, height;

public:
    void setWidth(int widthval){width = widthval;}
    void setHeight(int heightval){height = heightval;}
    int getArea(){return width*height;}
};

int main() {
    Rectangle rect;
    rect.setWidth(5);
    rect.setHeight(10);
    cout<< "rect shape : " << rect.getArea() << endl;
    return 0;

}
