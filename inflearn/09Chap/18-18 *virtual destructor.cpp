// 가상 소멸자 확인
// virtual ~AAA를 해야 메모리 누수 없이 메모리 해제 가능
// 메모리 누수 방지 확인: virtual ~AAA로 자식(BBB) 소멸자 호출 보장
// 업캐스팅 (AAA*로 BBB 객체): 동적 바인딩

#pragma warning(disable: 4996) // Code that generates C4996
#include <iostream>
#include <cstring>
using namespace std;

class AAA{
    char* str1;
public:
    AAA(const char* _str1)
    {
        
        str1 = new char[strlen(_str1)+1];
        strcpy(str1, _str1);
    }
    virtual ~AAA(){ //가상 소멸자 추가하기!
        cout<<"~AAA call!!"<<endl; 
    delete []str1;
    }
    virtual void ShowString()
    {
        cout<<str1<<endl;
    }
    
};

class BBB:public AAA
{
    char* str2;
public:
    BBB(const char* _str1, const char* _str2):AAA(_str1)
    {
        
        this->str2 = new char[strlen(_str2)+1];
        strcpy(this->str2, _str2);
    }
    ~BBB()
    {
        cout<<"~BBB() call!"<<endl;
        delete[] str2;
        
    }
    virtual void ShowString()
    {
        AAA::ShowString();
        cout<<str2<<endl;
    }
};

int main()
{
    AAA *a= new BBB("good", "evening");
    BBB *b = new BBB("good", "morning");
    a->ShowString();
    b->ShowString();

    cout<< " ---- object destructor ----"<<endl;
    delete a;
    delete b;
    return 0;
}
