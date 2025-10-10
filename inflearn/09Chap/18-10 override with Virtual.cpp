#include <iostream>
using namespace std;

class First{
public:
    virtual void MyFunc() {cout<<"First Func!"<<endl;}
};

class Second:public First
{
public:
    void MyFunc() override {cout<<"Second Func!"<<endl;} //override 명시 안해도 됨
};

class Third:public Second
{
public:
    void MyFunc() override {cout<<"Third Func!"<<endl;} //override 명시 안해도 됨
};

int main()
{
    Third *tptr = new Third();
    Second *sptr = tptr;
    First *fptr = sptr;

    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();

    delete tptr;
    return 0;
    // 포인팅의 형 상관 없이 포인터가 가리키는 객체의 마지막 오버라이딩 함수를 호출!
    // => 포인터 타입이 아닌 객체 실제 타입(Third)에 따라 Thid::myFunc 호출
    // 계속 overide되어서 동적으로 자식 자식을 가리키기때문에 third로 다 호출됨
    
}
