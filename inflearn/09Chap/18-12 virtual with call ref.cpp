#include <iostream>
using namespace std;

class Date
{
protected:
    int year, month, day;
public:
    Date(int y, int m , int d):year(y), month(m), day(d){}
    virtual void print() =0; //pure virtual function
};

class Adate : public Date
{
public:
    Adate(int y, int m, int d):Date(y, m, d){}
    void print(){ cout<< year << "/" << month << "/" << day<<endl; }
};

class Bdate :public Date
{
public:
    Bdate(int y, int m, int d):Date(y, m,d){}
    void print();
};

void Bdate::print()
{
    const char *mn[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "July", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    cout<<mn[month-1]<<' '<<day <<' '<<year<<endl;
}

int main()
{
    Adate a(1997,06,12);
    Bdate b(1995,10,12);
    
    Date &r1 =a, &r2=b;      //Date의 참조로 자식객체 upcasting!
    r1.print();
    r2.print();              // reference로 불러오기

    // Date *r1=&a, *r2=&b;
    // r1->print();
    // r2->print();                // pointer로써 불러오기 null확인해야함
    
    // a.print();
    // b.print();               // 그냥 객체로 불러오기
    
    return 0;
}


//
