#include <iostream>
using namespace std;

class Power
{
    int kick, punch;

public:
    Power(int k=0, int p=0):kick(k), punch(p){}
    void show(){ cout<<"Kick: "<<kick<<", Punch: "<<punch<<endl;}
    Power& operator++();            // 내부 함수로써 전치 ++ 선언
    Power operator++(int a);        // 내부 함수로써 후치 ++ 선언
    
};

Power& Power::operator++()
{
    kick++;
    punch++;
    return *this;
}
Power Power::operator++(int a)
{
    Power temp;
    temp.kick = this->kick++;
    temp.punch = this->punch++;
    return temp;
}


int main()
{
    Power a(3,4), b(5,6), c;
    c=a++;
    a.show();
    c.show();

    c = ++b;
    b.show();
    c.show();
    
    
    return 0;
}
