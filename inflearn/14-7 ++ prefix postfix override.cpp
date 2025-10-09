#include <iostream>
using namespace std;


class Power {
    int kick, power;
public:
    Power(int k =0, int p=0):kick(k),power(p){}
    void show();
    friend Power& operator++(Power &p);         //전위 ++ 연산자 함수 프렌드
    friend Power operator++(Power &p, int x);   //후위(코스타) ++ 연산자 함수 프렌드
};

void Power::show() {
    cout<< "kick : " << kick << " power : " << power << endl;
}
Power& operator++(Power &p) {
    p.kick++;
    p.power++;
    return p;
}

Power operator++(Power &p, int x) {
    Power tmp = p;
    p.kick++;
    p.power++;
    return tmp;
}


    int main() {
        Power a(4,7), b;
    b=a++;
    cout<<"a : ";
    a.show();
    cout<<"b : ";
    b.show();

    b=++a;
    cout<<"a : ";
    a.show();
    cout<<"b : ";
    b.show();




    return 0;
}
