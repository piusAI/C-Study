#include <iostream>
using namespace std;

class Power {
private:
    int kick, punch;
public:
    Power(int k=0, int p=0): kick(k), punch(p){}
    Power operator+(int op1); //은미쌤은 삼항연산자로 넣음
          //=> 더하는 이항 연산자(+) 이기에 두개 인자 받아서 처리함!
    void show(){ cout<<kick<<" "<<punch<<endl; }
};

Power Power::operator+(int op1) { 
    Power temp;
    temp.kick = this->kick+op1;
    temp.punch = this->punch+op1;
    return temp;
}

int main() {
    Power p0, p1(2,4);

    p0 = p1 + 2;

    cout<<"p0 : ";
    p0.show();

    cout<<"p1 : ";
    p1.show();
    return 0;
}
