#include <iostream>
using namespace std;

class Date {
    friend bool equals(Date d1, Date d2);
    int year, month, day;
public:
    Date(int y=0, int m=0, int d=0):year(y), month(m), day(d) {}
};

bool equals(Date d1, Date d2) {
    return d1.year==d2.year && d1.month==d2.month && d1.day==d2.day;
}

int main() {
    Date d1(2024,4,15), d2(2024,4,15), d3(0,0,1);

    cout<< "d1==d2? " <<boolalpha << equals(d1,d2)<<endl;
    cout<< "d2==d3? " <<boolalpha << equals(d2,d3)<<endl;
    return 0;
}
