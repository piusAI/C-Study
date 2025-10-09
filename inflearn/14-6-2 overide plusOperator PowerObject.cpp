#include <iostream>
using namespace std;

class Power {
    int kick;
    int punch;

public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show();
    friend Power operator+(const Power &op1, const Power &op2);
};

void Power::show() {
    cout<<"kick : "<<kick<<", punch : "<<punch<<endl;
}

Power operator+(const Power& op1, const Power &op2) {
    Power tmp;
    tmp.kick = op1.kick + op2.kick;
    tmp.punch = op1.punch + op2.punch;
    return tmp;
}

int main() {
    Power a(3,5), b(4,5), c;
    a.show();
    b.show();

    c=b+a;
    c.show();

    return 0;
}
