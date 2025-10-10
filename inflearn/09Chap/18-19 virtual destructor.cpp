#include <iostream>
#include <cstring>
using namespace std;


class Base {
public:
     virtual ~Base(){ cout<<"Base destructor"<<endl; } //사실 derived에 동적 메모리 할당이 없기 떄문에
    // virtual로 소멸자 자식까지 할 필요 없긴함

};

class Derived: public Base {
public:
    virtual ~Derived(){ cout << "Derived destructor" << endl; }
};

int main() {

    Base *bp = new Derived;
    Derived *dp = new Derived;

    delete bp;
    delete dp;
}
