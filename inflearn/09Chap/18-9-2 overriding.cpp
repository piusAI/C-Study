#include <iostream>
using namespace std;

class Base
{
public:
    virtual void f() {cout << "Base ::f() called "<<endl;}
};

class Derived:public Base
{
public:
    virtual void f() {cout<< "Derived ::f() called "<<endl;}
};


int main()
{
    Derived d, *pDer;

    pDer=&d;
    pDer->f();
    
    Base *pBase;
    pBase = pDer;   // upcasting으로 Derive class를 가리킨다.
                    // Base::f()가 virtual이므로, Derivde::f()가 overriding!
    pBase->f();     // 런타임에 base를 가리키지만, 동적바인딩으로 자식의 Derive ::f() 호출
    
}
