#include <iostream>
using namespace std;

class Calculator
{
protected:
    int a, b;
    
public:
    Calculator(int a, int b):a(a), b(b){}
    virtual int add(int a, int b)=0;
    virtual int subtract(int a, int b)=0;
    // average: 외부 배열과 크기로 평균 계산, 클래스 멤버 c[], size 불필요
    virtual double average(int c[], int size)=0;  //외부 배열 처리
};

class GoodCalc: public Calculator
{

public:
    GoodCalc(int a=0, int b=0):Calculator(a,b){}
    int add(int a, int b) {return a+b;}
    int subtract(int a, int b){ return a-b;}
    double average(int c[], int size)        //굳이 멤버 함수 매개변수로 쓴다고해도, 외부 데이터에서 처리.
    {
        double sum =0;
        for (int i =0 ; i<size ; i++)
        {
            sum+=c[i];
        }
        return sum/size;
    }
};

int main()
{
    int a[] = {1,2,3,4,5};
    
    Calculator *p = new GoodCalc();
    //GoodCalc *pg=new GoodCalc();
    cout<< p->add(4,5) << endl;
    cout<< p->subtract(4,5) << endl;
    cout<< p->average(a,5) << endl;
    delete p;
}
