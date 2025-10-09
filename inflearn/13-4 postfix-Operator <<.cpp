#include <iostream>
using namespace std;

class Power {
private:
    int kick, punch;
public:
    Power(int k=0, int p=0): kick(k), punch(p){}
    Power operator+(int op1);
    void show(){ cout<<kick<<" "<<punch<<endl; }
    Power& operator<<(int n);
};
Power& Power::operator<<(int n) {
    kick += n;
    punch +=n;
    return *this;
}

Power Power::operator+(int op1) {
    Power temp;
    temp.kick = this->kick+op1;
    temp.punch = this->punch+op1;
    return temp;
}

int main() {
    Power p0, p1(2,4), p2(5,6);

    p0 = p1 + 2;

    cout<<"p0 : ";
    p0.show();

    cout<<"p1 : ";
    p1.show();



    cout<<"p2 : ";
    p2.show();

    p2<<5<<2<<3;
    cout<<"p2 : ";
    p2.show();
    return 0;
}
