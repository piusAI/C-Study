#include <iostream>
#include <string>
using namespace std;


class Circle
{
private:
    int x,y;
    int radius;

public:
    //Static 변수
    static int count;
    Circle(): x{0}, y{0}, radius{0}
    {
        count++;
    }
    Circle(int x, int y, int r) : x{x}, y{y}, radius{r}
    {
        count ++;
    }
    ~Circle(){ count--;}
    

    // static 멤버 함수
    static int getCount()
    {
        return count;
    }
};

int Circle::count=0;

int main()
{
    Circle c1;
    cout << "create number of now circle object : "<< Circle::getCount()<<endl;
    Circle c2;
    cout << "create number of now circle object : "<< Circle::getCount()<<endl;
    
    return 0;
}
