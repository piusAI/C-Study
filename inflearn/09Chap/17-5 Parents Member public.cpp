#include <iostream>
using namespace std;

class Base
{
public:
    int x;
protected:
    int y;
private:
    int z;
    
};

class Derived: public Base // pubilc x는 접근 가능
// class Derived : private Base // 모든 base calss 멤버변수 접근 불가
{
    
};
int main()
{
    Derived dr;
    dr.x=2;
    cout<<dr.x<<endl;
    return 0;
}
