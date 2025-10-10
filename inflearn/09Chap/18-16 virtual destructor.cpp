// virtual Destructor 구현
// 포인터 타입의 upcasting 형전환 (shape ->rect)

#include <iostream>
using namespace std;

class Shape
{
protected:
    const int x,y;
public:
    Shape(int x, int y):x(x),y(y){}
    virtual void draw() const =0; //const로 선언해 초기화 후 수정 방지
    virtual ~Shape() {cout<<"Shape virtual destructor"<<endl;} //가상 소멸자
};

class Rect:public Shape
{
private : int width, height;
public:
    Rect(int x, int y, int width, int height):Shape(x, y), width(width), height(height){}
    void draw() const override //
    {
        cout<<"Rectangle Draw"<<endl;   //virtual 함수 자식에서 꼭 구현!
    }
    ~Rect(){cout<<"Rect Destructor "<< endl;}
};

int main()
{   //shape은 추상이어서 객체는 못만들지만 pointer를 만들 수 있음!
    Shape *ps = new Rect(0,0,100,100); // 포인터 타입은 Shape* 유지, new Rect로 Rect 객체 가리켜 동적 바인딩
    ps->draw();
    delete ps;

    return 0;
}
