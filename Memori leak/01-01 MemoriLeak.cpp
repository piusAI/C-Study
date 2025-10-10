// 메모리 누수를 확인하는 방법?
//   01 스마트포인터(추후 더 공부하기)
//   02 그냥 소멸자에 찍어보자!

// 02의 활용에 있어서, Circle 소멸자가 반환하고 있지 않아서 누수 발생 하고있음을 아랐음!

// Memori Leak
// -> 소멸자가 부모의 소멸자만 실행한다
//  
// 해결책 : virtual 소멸자를 넣어줘야함!
// 자식의 소멸자까지 내려갈 수 있도록!

#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    ~Shape(){ cout<<"Shape Destructor"<< endl;}
  //virtual ~Shape(){}                            ---해결책
};

class Circle:public Shape {
    int *data;// 동적 자원
public:
    Circle() : data(new int[100]){}
    ~Circle() {
        delete []data;
        cout<<"Circle Destructor!"<<endl;
    }
};

int main() {

    Shape *p=new Circle;
    delete p;
}
