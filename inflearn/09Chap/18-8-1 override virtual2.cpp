#include <iostream>
using namespace std;

class Base
{
    // int t;
public:
    virtual void fail();
    virtual void success();
    virtual void g(int);
    
};

class Derived : public Base
{
private:
    // int TT;
public:
    // virtual int fail(); // error    
    virtual void success();
    virtual void g(int, double); // 오버라이딩 실패, 오버로딩 성공
    void fail(); //virtual 생략 가능
    
};
int main()
{
}
