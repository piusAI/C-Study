#include <iostream>
using namespace std;

class Pointer {

private:
    int *p;
public:
    Pointer(int *p):p(p){}
    ~Pointer() { delete p; }
    int* operator->()const {return p;}  // -> override
    int& operator*()const {return *p;}  // * override
};

int main() {
    /*
    int *t;
    t=new int;
    Pointer p(t);
    */
    //이런식으로 할당해도 됨
    Pointer p(new int); //동적 할당!
    *p=100;
    cout<<*p<<endl;


    return 0;
}
