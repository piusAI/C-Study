#include <iostream>

using namespace std;

class A {
public:
    A(){ cout<< "Constructor A "<<endl;}
    A(int x) {
        cout<< "paraameter Constructor A"<< x<< endl;
    }
};

class B: public A {
public:
    B() { //A() 호출 되도록 암시적 컴파일
        cout<<"Constructor B" <<endl;
    }
};

int main() {
    B b;
    return 0;
}
