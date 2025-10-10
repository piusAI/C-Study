#include <iostream>
using namespace std;

class Base
{
public:
    virtual void f(){cout<<"base::f() called"<<endl;}
    
};

class Derived : public Base
{
public:
    void f() {cout<<"Derived::f() called"<<endl;}
};

class GrandDerived : public Derived
{
public:
    void f() {cout<<"GrandDerived::f() called"<<endl;} //virtual, override 생략 가능
};

int main()
{
    GrandDerived g; //가장 자식의 객체
    Base *bp;
    Derived *dp;
    GrandDerived *gp;

    bp = dp = gp = &g; //g시작 주소를 다 가리킴

    bp->f();
    dp->f();
    gp->f();

    //동적 바인딩에 의해 가장 자식의 객체 g에서 호출!
    //모든 포인터는 생성된 객체타입이 g이기 때문에,
    //g에 있는 virutal 함수로 호출됨!
    //=>동적 바인딩 때문에!
    
    return 0;
}
