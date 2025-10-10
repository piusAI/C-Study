#include <iostream>
using namespace std;

class Base
{
public:
    void f() {cout << "Base ::f() called "<<endl;}
};

class Derived:public Base
{
public:
    void f() {cout<< "Derived ::f() called "<<endl;}
};


int main()
{
    Derived d, *pDer;

    pDer=&d;
    pDer->f();
    
    Base *pBase;
    pBase = pDer;   // upcasting으로 Derive class를 가리키지만,
                    // 자식의 void f()를 가지지 않기 때문에, 부모인
    pBase->f();     // Base :f() 호출
    
}

// virtual이 아니어서, 재정의도 아니고, 함수의 중복도 아니고, 함수의 숨김임!
