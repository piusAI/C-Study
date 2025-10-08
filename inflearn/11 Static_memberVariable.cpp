#include <iostream>
#include <string>
using namespace std;


class Circle
{
private:
    int x,y;
    int radius;

public:
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
    
};

int Circle::count=0;

int main()
{
    Circle c1;
    Circle c2;
    cout<<Circle::count;

    
    return 0;
}


