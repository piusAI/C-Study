#include <iostream>
#include <string>
using namespace std;

class ParentClass{
public:
    void print() {
        cout<< "Parent class print! "<<endl;
    }


};

class ChildClass:public ParentClass {
    int data;
public:
    void print() {                   //member 함수 재정의
        ParentClass::print();        // 부모 함수 print 호출!
        cout<< "Child class print!"<<endl;
    }
};

int main() {
    ChildClass cc;
    cc.print();
    return 0;
}
