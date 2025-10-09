#include <iostream>

using namespace std;

class A {
public:
    A(){ cout<< "Constructor A "<<endl;}
    A(int x) {
        cout<< "paraameter Constructor A : "<< x<< endl;
    }
};

class B: public A {
public:
    B() { //A() 호출 되도록 암시적 컴파일
        cout<<"Constructor B" <<endl;
    }
    B(int x) : A(x+3) { //A(int x)로써 호출!
        cout<< "parameter constructor B : "<<x<<endl;
    }
};

int main() {
    B b(5);
    return 0;
}
