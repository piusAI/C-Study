#include <iostream>
using namespace std;

class Power
{
    int kick, punch;

public:
    Power(int k=0, int p=0):kick(k), punch(p){}
    void show(){ cout<<"Kick: "<<kick<<", Punch: "<<punch<<endl;}
    Power& operator++();
    Power operator++(int a);
    Power operator+(Power &op2);

    bool operator==(const Power &op2);
};

bool Power::operator==(const Power &op2)
{
    if (this->kick ==op2.kick && this->punch==op2.punch){ return true; }
    else{ return false; }
    
}

Power Power::operator+(Power &op2)
{
    Power tmp;
    tmp.kick = this->kick + op2.kick;
    tmp.punch = this->punch + op2.punch;
    return tmp;
}

Power& Power::operator++()
{
    kick++;
    punch++;
    return *this;
}
Power Power::operator++(int a)
{
    Power temp=*this;
    this->kick++;
    this->punch++;
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

    Power a1(30,40), b1(50,60), c1;
    c1= a1+b1;

    c1.show();

    cout<< "a1 b1 equals?? : ";
    cout<< boolalpha<< (a1==b1)<<endl;

    cout<< "b c equals?? : ";
    cout<< boolalpha<< (b==c)<<endl;
    
    return 0;
}
