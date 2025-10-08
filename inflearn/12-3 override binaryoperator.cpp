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
    void print();
    Power operator+(const int &amount);      // + operator int override
    Power operator+(const Power &op2);      // + operator override
    bool operator==(const Power &op3);      // == operator override
    Power& operator +=(const Power &op4);   // += operator override

};

//return type : reference  & pointer value
Power& Power::operator+=(const Power &op4) {
    this->kick +=op4.kick;
    this->punch +=op4.punch;
    return *this;
}
bool Power::operator==(const Power &op3) {
    if (this-> kick == op3.kick && this->punch ==op3.punch)
        {
        return true;
    }
    else {
        return true;
    }
}
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
Power Power::operator+(const int &amount) {
    Power tmp;
    tmp.kick = this->kick + amount;
    tmp.punch  = this->punch + amount;
    return tmp;
}

int main()
{
    Power p1(20,2);
    Power p2(40,-2);
    Power p3 = p1.operator+(p2);
    p3.print();

    Power p4(20,2);
    cout<<"p4 == p1? : "<<boolalpha<<p4.operator==(p1) <<endl;

    Power p5(1,8);
    p5.operator+=(p1);
    p5.print();

    Power a(3,5), b(4,5), c;
    c= a+=b; // 파워 객체 더하기
    c.print();

    Power h(7,11), t;
    t=h+2;
    t.print();

    return 0;
}
