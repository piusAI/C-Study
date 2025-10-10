//다형성 예제 : virtual로 shape에서 rect draw 오버라이딩
//shape *ps로 Rect 객체를 가리킴, ps->draw는 Rect::draw()를 호출

#include <iostream>
using namespace std;

class Shape
{
    protected:
    int x,y;
public:
    Shape(int x, int y):x(x),y(y){}
    virtual void draw() //순수 가상 함수는 아니다잉!
    {
        cout<<"Shape Draw"<<endl;
    }
};

class Rect:public Shape
{
private :
    int width, height;
public:
    Rect(int x, int y, int width, int height):Shape(x,y), width(width), height(height){}
    void draw()
    {
        cout<<"Rectangle Draw"<<endl;
    }
};

int main()
{
    Shape *ps = new Rect(0,0, 100, 100); // Rect를 가리킨다
    ps->draw(); //Rect인 자식 class의 draw가 시행되겠다!

    delete ps;
    return 0;
}
