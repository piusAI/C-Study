#include <iostream>
#include <cstring>
using namespace std;

class Base{
public:
    int baseValue= 1;
    virtual ~Base(){ cout<< "Base Destructor"<< endl;}
    void show() {cout << "Base : "<<baseValue<<endl;}
};

class Derived : public Base {
public:
    int extra = 10;
    void showExtra(){ cout << "Derived : "<<extra<<endl;}
    ~Derived(){cout << "Derived Destructor"<< endl;}
};

int main() {
    // 01 : Base 에서의 derived 추가 멤버 접근 당연히 불가!!
    Base *b1 = new Derived;
    b1->show();
    // b1 ->extra; //error


    //02 : DownCasting!
    Derived* d1 = dynamic_cast<Derived*>(b1);
    if (d1) d1->showExtra(); //Derived : 10

    //03 묵시적 upCasting!
    Derived* d2 = new Derived;
    Base *b2 = d2; // 묵시적 Upcasting!
    b2->show();

    delete b1;
    delete b2;
    return 0;
}

