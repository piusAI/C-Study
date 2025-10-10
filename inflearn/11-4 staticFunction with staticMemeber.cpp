#include <iostream>
#include <string>
using namespace std;

class Circle
{
private:
    static int numOfCircles;
    int radius;

public:
    Circle(int r =1);
    ~Circle(){numOfCircles--;} // 소멸자 1개 감소
    
    double getArea() {return 3.14 * radius *radius ; }
    static int getNumofCircles(){ return numOfCircles; }
};

Circle ::Circle(int r)
{
    this->radius = r;
    numOfCircles++; //생성된 원의 개수 증가
}

int Circle::numOfCircles=0; // 0으로 초기화, private여도 Circle에서 접근한거여서 ㄱㅊ

int main()
{
    Circle *p = new Circle[10]; // 동적 할당 =>default 생성자 r=1로 호출 10개
    cout<<"number of Circles? : "<<Circle::getNumofCircles()<<endl;
    // 10개 

    delete []p; // 10개 다 지워뿌라! - numOfCircle--;
    cout<<"number of Circles? : "<<Circle::getNumofCircles()<<endl;
    // 0개 

    Circle a;
    cout<<"number of Circles? : "<<Circle::getNumofCircles()<<endl;
    // 1개
    
    Circle b;
    cout<<"number of Circles? : "<<Circle::getNumofCircles()<<endl;
    // 2개
    return 0;
}
