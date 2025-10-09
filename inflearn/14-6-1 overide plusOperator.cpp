#include <iostream>

using namespace std;
class Power {
    int kick;
    int punch;

public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show();
    friend Power operator+(int a, const Power &op2);
};

void Power::show() {
    cout<<"kick : "<<kick<<", punch : "<<punch<<endl;
}

Power operator+(int op1, const Power &op2) {
    Power tmp;
    tmp.kick = op1+ op2.kick;
    tmp.punch =  op1+ op2.punch;
    return tmp;
}

int main() {
    Power a(3,5), b;
    a.show();
    b.show();

    b= 2+a;
    a.show();
    b.show();

    return 0;
}
