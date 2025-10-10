#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw()
{
    cout<<" --Shape--";
}
    
};
class Circle : public Shape
{
public:
    virtual void draw()
    {
        Shape::draw(); //기본 calss draw()!
        cout<<"--Circle--"<<endl;
    }
};


int main()
{
    Shape *shp = new Circle();
    shp->draw();
    shp-> Shape::draw();
    delete shp;
    return 0;
}
