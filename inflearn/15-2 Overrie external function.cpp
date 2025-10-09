#include <iostream>
using namespace std;

class Power
{
    int kick, punch;

public:
    Power(int k=0, int p=0):kick(k), punch(p){}
    void show(){ cout<<"Kick: "<<kick<<", Punch: "<<punch<<endl;}
    friend Power operator+(const Power &p1, const Power &p2);

    friend ostream& operator <<(ostream& os, Power op2);
};

ostream& operator <<(ostream& os, Power op2)
{
    os<<"Kick : "<<op2.kick <<", Punch:"<<op2.punch<<endl;
    return os;
}
Power operator+(const Power &p1, const Power &p2)
{
    Power tmp;
    tmp.kick=p1.kick+p2.kick;
    tmp.punch=p1.punch+p2.punch;
    return tmp;
    
}

int main()
{
    Power a(3,4), b(5,6), c;

    c=a+b;
    c.show();
    cout<<a<<b<<c;
    return 0;
}
