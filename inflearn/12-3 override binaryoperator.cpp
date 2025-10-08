#include <iostream>
using namespace std;

class Power
{
private :
    int kick, punch;
public:
    Power(int kick=0, int punch=0)
    {
        this->kick = kick;
        this->punch = punch;
    }
    Power operator+(const Power &op2);
    void print();
    
};
void Power::print()
{
    cout<< this->kick << " "<<this->punch <<endl;
}
Power Power::operator+(const Power &op2)
{
    Power tmp;
    tmp.kick = this->kick + op2.kick;
    tmp.punch = this->punch + op2.punch;
    return tmp;
}

int main()
{
    Power p1(20,2);
    Power p2(40,-2);
    Power p3 = p1.operator+(p2);
    p3.print();
    
    return 0;
}
