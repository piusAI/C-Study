#include <iostream>
using namespace std;

struct Data {
    int value;
    Data(int v =0) : value(v){}
};

class Pointer {
private:
    Data *p;
public:
    Pointer(Data *p) :p(p){}
    ~Pointer() {delete p;}
    Data* operator->() const{return p;}
    Data& operator*() const{return *p;}
};

int main() {

    Pointer p1(new Data);
    *p1 = Data(100);                //operator*로 data 객체 설정
    cout<< "using *p1 : "<< (*p1).value << endl;

    Pointer p2(new Data);
    p2->value =200;                     //operator->로 멤버 접근!
    cout << "using *p2 : "<< p2->value << endl;

    return 0;
}
