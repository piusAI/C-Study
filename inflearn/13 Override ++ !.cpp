#include <iostream>
using namespace std;


class Power {
private:
    int kick, punch;

public:
    Power(int k=0, int p=0):kick(k), punch(p){};
    Power& operator++();
    bool operator!();
    void show(){cout<<"Kick : "<<this->kick<<" Punch : "<<this->punch;};
};
//반드시 자신을 Return!
Power& Power::operator++() {
    this->kick ++;
    this->punch ++;
    return *this;
}

bool Power::operator!() {
    if (this->kick ==0 && this->punch ==0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    Power p0, p1(2,4);
    p1.operator++(); // operator ++()
    p0= ++p1;        // 전위 ++;

    cout<<"p0 : ";
    p0.show();
    cout<<endl;

    cout<<"p1 : ";
    p1.show();       // operator++
    cout<<endl;

    //operator !();
    Power p3, p4(1,0);
    cout<<boolalpha<<p3.operator!()<<endl;
    cout<<boolalpha<<p4.operator!()<<endl;

    //전위 !();
    cout<<boolalpha<<!p3<<endl;


    return 0;
}
