#include <iostream>
#include <cstring>
using namespace std;


class String {
    char* s;
public:
    String(char* p) {
        cout<<"String() constructor"<<endl;
        s= new char[strlen(p)+1];                   // 01 부모 동적 메모리 할당
        strcpy(s, p);
    }
    virtual ~String() {                             // 03 그렇다면! 가상 소멸자 꼭 넣어야지 자식까지 내려간다!
        cout<<"String() destructor! "<<endl;
        delete []s;                                 // 01-01 요기서 메모리 해제하는군
    }

    virtual void display() {
        cout<<s;
    }
};


class MyString: public String {
    char *header;
public:
    MyString(char *h, char *p):String(p) {
        cout<<"MyString() constructor"<<endl;
        this->header =new char[strlen(h)+1];             // 02 자식도 동적 메모리 할당
        strcpy(this->header,h);
    }
    ~MyString() {
        cout<<"MyString() destructor! "<<endl;
        delete []header;                                // 02-01 여기서 메모리 해제 하겠지? 
    }

    void display() {
        cout<<header;
        String::display();
        cout<<header<<endl;
    }
};


int main() {
    String *p= new MyString("-----","Pius !");
    p->display();
    delete p;

    return 0;
}

