// virtual과 싸워서 이긴 나.. 칭찬해..
// virtual소멸자는 그냥 활용해야하는것이 아니라
// 동적 메모리를 할당 하고있는 derive class들에 한에 꼭 메모리 해제 해야함
// 그렇지 않다면 메모리 누수가 발생하는거여쓰!

#include <iostream>
#include <cstring>
using namespace std;

class AAA {
    char* str1;

public:
    AAA(const char* _str1) {
        str1=new char[strlen(_str1)+1];
        strcpy(str1, _str1);
    }
    ~AAA(){ delete []str1; cout<<"~AAA"<<endl; } //  02 그래서 여기를 virtual로 derive class 소멸자로도 가야함!

    virtual void ShowString() {
        cout<<str1<<" ";
    }
};

class BBB: public AAA {
    char* str2;

public:
    BBB(const char* _str1, const char* _str2):AAA(_str1) {
        str2 = new char[strlen(_str2)+1];
        strcpy(str2, _str2);
    }
    ~BBB(){ delete []str2; cout<<"~BBB"<<endl;} // 01 지금 여기서 누수가 발생하고있음! 소멸자가 제대로 발현되고있찌 않소!

    void ShowString() {
        AAA::ShowString();
        cout<<"child : "<<str2<<endl;
    }

};

int main() {
    AAA *pa = new BBB("Ronal", "do");
    BBB *pb = new BBB("Sonla","do");

    pa->ShowString();
    pb->ShowString();
    cout<< "--- before deconstructor --- "<<endl;
    delete pa;
    delete pb;

    return 0;
}
