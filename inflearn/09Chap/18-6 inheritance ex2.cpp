#include <iostream>
#include <string>
using namespace std;


class Shape{
    int x, y;
public:
    Shape(int x=0, int y=0):x(x),y(y){} //생성자 인자 있는거 없는거 통합.
    void setX(int x){ this->x =x;}
    void setY(int y){ this->y = y;}
    int getX(){return x;}
    int getY(){return y;}
    void draw(){cout<<"shape draing... "<<endl;} //추후 추상클래스 일때 비워둘 수도 있음
    int getArea(){return 0;}
};

class Circle:public Shape {
    int r;
public:
    Circle(int r, int x, int y):Shape(x,y), r(r){}
    void draw() { //overide, 재정의 :부모 메서드 재정의 (같은 시그니처)
        cout<<"Circle drawing" <<endl;
    }
    int getArea(){ return 3.14*r*r ;} //같은 시그니처 : 오버라이딩, 재정의
};


class Rect:public Shape {
    int w, h;
public:
    Rect(int w, int h, int x, int y):Shape(x, y), w(w), h(h){}
    void draw() {
        cout<<"rect drawing" <<endl;
    }
    int getArea(){return w*h;}
};

int main() {
    Circle c(10, 1,1);
    Rect r(10,20, 1,1);

    c.draw();
    r.draw();

    c.setX(20);
    cout<<c.getArea()<<endl;




    return 0;

}
