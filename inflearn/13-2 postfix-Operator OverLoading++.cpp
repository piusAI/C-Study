#include <iostream>

using namespace std;

class Power {

private:
    int kick, punch;
public:
    Power(int k=0, int p=0): kick(k), punch(p){}
    Power operator++(int x);
    void show(){ cout<<kick<<" "<<punch<<endl; }

};

Power Power::operator++(int x) { //후위 ++ 연산자 함수 선언
    Power temp=*this;
    this->kick++;
    this->punch++;
    return temp;

    // 이런식으로 바로 this를 리턴해주면 후위연산자 의미 위배
    // return *this;
}

int main() {
    Power p0, p1(2,4);
    p0=p1++;

    cout<<"p0 : "; //p0 들어온 p1 그대로다!
    p0.show();
    cout<<"p1 : "; //p1는 1이 더해지겠지만
    p1.show();
    return 0;
}
