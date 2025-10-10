#include <iostream>

using namespace std;

class Shape
{
public:
    void paint()
    {
        draw();
    }
    virtual void draw()
    {
        cout<<"Shape : draw!"<<endl;
    }
};

class Circle:public Shape
{
public:
    void draw(){ cout<<"Circle : draw!"<<endl;}
};

int main()
{
    Shape *ps=new Circle; //upcasting
    ps->draw();
    delete ps;
    
}
