#include <iostream>
using namespace std;

class Data {
    int year, month, day;

public:
    Data( int y, int m, int d): year(y), month(m), day(d) {}
    void print() {
        cout<< year<<"."<<month<<"."<<day<<endl;
    }
};

class Person {
    string name;
    Data birth;
public:
    Person(string n, Data d):name(n), birth(d){}
    void print() {
        cout<<name<<":";
        birth.print();
        cout<<endl;
    }
};


int main() {
    Data d(1997,06,12);
    Person p("Pius", d);
    p.print();



    return 0;
}
